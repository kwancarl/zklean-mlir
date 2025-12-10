#include "lib/Conversion/Passes.h"
#include "lib/Dialect/ZKLean/ZKLeanDialect.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"

int main(int argc, char **argv) {
  mlir::DialectRegistry registry;
  registry.insert<mlir::zklean::ZKLeanDialect>();
  mlir::registerAllDialects(registry);
  mlir::registerAllPasses();
  mlir::zklean::registerZKLeanConversionPasses();

  return mlir::asMainReturnCode(
      mlir::MlirOptMain(argc, argv, "ZKLean Driver", registry));
}
