#include "lib/Dialect/ZKLean/ZKLeanDialect.h"

#include "lib/Dialect/ZKLean/ZKLeanOps.h"
#include "lib/Dialect/ZKLean/ZKLeanTypes.h"
#include "mlir/include/mlir/IR/Builders.h"
#include "llvm/include/llvm/ADT/TypeSwitch.h"

#include "lib/Dialect/ZKLean/ZKLeanDialect.cpp.inc"
#define GET_TYPEDEF_CLASSES
#include "lib/Dialect/ZKLean/ZKLeanTypes.cpp.inc"
#define GET_OP_CLASSES
#include "lib/Dialect/ZKLean/ZKLeanOps.cpp.inc"

namespace mlir {
namespace zklean {

void ZKLeanDialect::initialize() {
  addTypes<
#define GET_TYPEDEF_LIST
#include "lib/Dialect/ZKLean/ZKLeanTypes.cpp.inc"
      >();
  addOperations<
#define GET_OP_LIST
#include "lib/Dialect/ZKLean/ZKLeanOps.cpp.inc"
      >();
}

} // namespace zklean
} // namespace mlir
