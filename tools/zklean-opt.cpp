#include "lib/Conversion/Passes.h"
#include "lib/Dialect/ZKLean/ZKLeanDialect.h"

// TODO: Clean up includes
// No need to include ZKExpr since ZKBuilder already includes ZKExpr
// #include "lib/Dialect/ZKExpr/ZKExprDialect.h"
#include "lib/Dialect/ZKBuilder/ZKBuilderDialect.h"

#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

int main(int argc, char **argv) {
  mlir::DialectRegistry registry;
  registry.insert<mlir::zklean::ZKLeanDialect>();
  registry.insert<mlir::zkexpr::ZKExprDialect>();
  registry.insert<mlir::zkbuilder::ZKBuilderDialect>();
  mlir::registerAllDialects(registry);
  mlir::registerAllPasses();
  mlir::zklean::registerZKLeanConversionPasses();

  return mlir::asMainReturnCode(
      mlir::MlirOptMain(argc, argv, "ZKLean Driver", registry));
}
