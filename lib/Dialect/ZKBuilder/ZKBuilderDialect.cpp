#include "lib/Dialect/ZKBuilder/ZKBuilderDialect.h"

#include "lib/Dialect/ZKBuilder/ZKBuilderOps.h"
#include "lib/Dialect/ZKBuilder/ZKBuilderTypes.h"
#include "mlir/include/mlir/IR/Builders.h"
#include "llvm/include/llvm/ADT/TypeSwitch.h"

#include "lib/Dialect/ZKBuilder/ZKBuilderDialect.cpp.inc"
#define GET_TYPEDEF_CLASSES
#include "lib/Dialect/ZKBuilder/ZKBuilderTypes.cpp.inc"
#include "lib/Dialect/ZKExpr/ZKExprTypes.cpp.inc"
#define GET_OP_CLASSES
#include "lib/Dialect/ZKBuilder/ZKBuilderOps.cpp.inc"

namespace mlir {
namespace zkbuilder {

void ZKBuilderDialect::initialize() {
  addTypes<
#define GET_TYPEDEF_LIST
#include "lib/Dialect/ZKBuilder/ZKBuilderTypes.cpp.inc"
      >();
  addOperations<
#define GET_OP_LIST
#include "lib/Dialect/ZKBuilder/ZKBuilderOps.cpp.inc"
      >();
}

} // namespace zkbuilder
} // namespace mlir
