#include "lib/Conversion/Passes.h"

#include "lib/Dialect/ZKLean/ZKLeanDialect.h"
#include "lib/Dialect/ZKLean/ZKLeanOps.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/Dialect.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"

// TODO: Figure out how to include LLZK dialect in here
#if __has_include("llzk/Dialect/InitDialects.h")
#include "llzk/Dialect/InitDialects.h"
#define ZKLEAN_LLZK_HAS_DIALECT_HEADERS 1
#else
#define ZKLEAN_LLZK_HAS_DIALECT_HEADERS 0
#endif

#ifndef ZKLEAN_LLZK_ENABLE_DIALECT_REGISTRATION
#define ZKLEAN_LLZK_ENABLE_DIALECT_REGISTRATION 0
#endif

namespace mlir {
namespace zklean {

/// Placeholder demonstrating how to plug zkLean ops into the conversion
/// infrastructure when targeting LLZK dialects. Replace the body with real
/// LLZK later.
struct ZKExprAddOpToLLZK
    : public OpConversionPattern<AddOp> {
  using OpConversionPattern::OpConversionPattern;

  LogicalResult
  matchAndRewrite(AddOp op, OpAdaptor adaptor,
                  ConversionPatternRewriter &rewriter) const final {
    return rewriter.notifyMatchFailure(
        op, "LLZK conversion not implemented yet");
  }
};

struct ConvertZKLeanToLLZKPass
    : public PassWrapper<ConvertZKLeanToLLZKPass, OperationPass<ModuleOp>> {
  MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(ConvertZKLeanToLLZKPass)

  StringRef getArgument() const final { return "convert-zklean-to-llzk"; }
  StringRef getDescription() const final {
    return "Template conversion pass from the zkLean dialect to LLZK";
  }

  void getDependentDialects(DialectRegistry &registry) const final {
    registry.insert<zklean::ZKLeanDialect>();
#if ZKLEAN_LLZK_HAS_DIALECT_HEADERS &&                                    \
    ZKLEAN_LLZK_ENABLE_DIALECT_REGISTRATION
    llzk::registerAllDialects(registry);
#endif
  }

  void runOnOperation() final {
    RewritePatternSet patterns(&getContext());
    patterns.add<ZKExprAddOpToLLZK>(&getContext());

    ConversionTarget target(getContext());
    target.addLegalOp<ModuleOp>();

    // Permit any dialect coming from LLZK for now. Restrict when conversions
    // are implemented so zkLean ops become illegal.

    target.markUnknownOpDynamicallyLegal([](Operation *op) {
      if (auto *dialect = op->getDialect())
        return dialect->getNamespace().starts_with("llzk");
      return true; // Allow builtin ops.
    });

    if (failed(applyPartialConversion(getOperation(), target, std::move(patterns))))
      signalPassFailure();
  }
};

std::unique_ptr<Pass> createConvertZKLeanToLLZKPass() {
  return std::make_unique<ConvertZKLeanToLLZKPass>();
}

} // zklean

} // mlir
