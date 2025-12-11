#ifndef LIB_DIALECT_ZKBUILDER_ZKBUILDERDIALECT_H_
#define LIB_DIALECT_ZKBUILDER_ZKBUILDERDIALECT_H_

// Required because the .h.inc file refers to MLIR classes and does not itself
// have any includes.
#include "mlir/include/mlir/IR/DialectImplementation.h"

#include "lib/Dialect/ZKBuilder/ZKBuilderDialect.h.inc"
#include "lib/Dialect/ZKExpr/ZKExprDialect.h.inc"

#endif  // LIB_DIALECT_ZKBUILDER_ZKBUILDERDIALECT_H_
