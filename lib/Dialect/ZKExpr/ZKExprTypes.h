#ifndef LIB_TYPES_ZKEXPR_ZKEXPRTYPES_H_
#define LIB_TYPES_ZKEXPR_ZKEXPRTYPES_H_

// Required because the .h.inc file refers to MLIR classes and does not itself
// have any includes.
#include "mlir/include/mlir/IR/DialectImplementation.h"

#define GET_TYPEDEF_CLASSES
#include "lib/Dialect/ZKExpr/ZKExprTypes.h.inc"

#endif  // LIB_TYPES_ZKEXPR_ZKEXPRTYPES_H_
