#include "lib/Conversion/Passes.h"

#include "mlir/Pass/PassRegistry.h"

namespace mlir {
namespace zklean {

void registerZKLeanConversionPasses() {
  registerPass([] { return createConvertZKLeanToArithPass(); });
  registerPass([] { return createConvertZKLeanToLLZKPass(); });
}

} // zklean
} // mlir
