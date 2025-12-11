#ifndef LIB_TYPES_ZKBUILDER_ZKBUILDERTYPES_H_
#define LIB_TYPES_ZKBUILDER_ZKBUILDERTYPES_H_

// Required because the .h.inc file refers to MLIR classes and does not itself
// have any includes.
#include "mlir/include/mlir/IR/DialectImplementation.h"

#define GET_TYPEDEF_CLASSES
#include "lib/Dialect/ZKBuilder/ZKBuilderTypes.h.inc"

#endif  // LIB_TYPES_ZKBUILDER_ZKBUILDERTYPES_H_
