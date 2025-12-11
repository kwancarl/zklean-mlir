#include "lib/Dialect/ZKExpr/ZKExprDialect.h"

#include "lib/Dialect/ZKExpr/ZKExprOps.h"
#include "lib/Dialect/ZKExpr/ZKExprTypes.h"
#include "mlir/include/mlir/IR/Builders.h"
#include "llvm/include/llvm/ADT/TypeSwitch.h"

#include "lib/Dialect/ZKExpr/ZKExprDialect.cpp.inc"
#define GET_TYPEDEF_CLASSES
#include "lib/Dialect/ZKExpr/ZKExprTypes.cpp.inc"
#define GET_OP_CLASSES
#include "lib/Dialect/ZKExpr/ZKExprOps.cpp.inc"

namespace mlir {
namespace zkexpr {

void ZKExprDialect::initialize() {
  addTypes<
#define GET_TYPEDEF_LIST
#include "lib/Dialect/ZKExpr/ZKExprTypes.cpp.inc"
      >();
  addOperations<
#define GET_OP_LIST
#include "lib/Dialect/ZKExpr/ZKExprOps.cpp.inc"
      >();
}

} // namespace zkexpr
} // namespace mlir
