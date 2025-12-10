#include "lib/Conversion/Passes.h"

#include "lib/Dialect/ZKLean/ZKLeanDialect.h"
#include "lib/Dialect/ZKLean/ZKLeanOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"

namespace mlir::zklean {
namespace {

/// Example pattern that shows how to lower a zkLean operation to another
/// dialect. Replace the body with the conversion logic you actually need.
struct ZKExprAddOpLowering : public ::mlir::OpConversionPattern<AddOp> {
  using Base = ::mlir::OpConversionPattern<AddOp>;
  using Base::Base;

  LogicalResult
  matchAndRewrite(AddOp op, typename Base::OpAdaptor adaptor,
                  ::mlir::ConversionPatternRewriter &rewriter) const final {
    // Returning failure keeps the original op in place; update this to rewrite
    // the op into the target dialect once the conversion is known.
    return rewriter.notifyMatchFailure(op, "no conversion implemented yet");
  }
};

struct ConvertZKLeanToArithPass
    : public PassWrapper<ConvertZKLeanToArithPass, OperationPass<ModuleOp>> {
  MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(ConvertZKLeanToArithPass)

  StringRef getArgument() const final { return "convert-zklean-to-arith"; }
  StringRef getDescription() const final {
    return "Template conversion pass from the zkLean dialect to arith";
  }

  void getDependentDialects(DialectRegistry &registry) const final {
    registry.insert<arith::ArithDialect, zklean::ZKLeanDialect>();
  }

  void runOnOperation() final {
    RewritePatternSet patterns(&getContext());
    patterns.add<ZKExprAddOpLowering>(&getContext());

    ConversionTarget target(getContext());
    target.addLegalDialect<arith::ArithDialect>();
    target.addLegalDialect<zklean::ZKLeanDialect>();
    target.addLegalOp<ModuleOp>();
    target.markUnknownOpDynamicallyLegal([](Operation *) { return true; });

    // applyPartialConversion succeeds immediately because all dialects are
    // marked legal above. Replace the target legality rules when you begin
    // migrating zkLean operations to other dialects.
    if (failed(applyPartialConversion(getOperation(), target,
                                      std::move(patterns))))
      signalPassFailure();
  }
};

} // namespace

std::unique_ptr<Pass> createConvertZKLeanToArithPass() {
  return std::make_unique<ConvertZKLeanToArithPass>();
}

} // namespace mlir::zklean
