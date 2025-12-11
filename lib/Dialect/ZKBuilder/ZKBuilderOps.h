#ifndef LIB_DIALECT_ZKBUILDER_ZKBUILDEROPS_H_
#define LIB_DIALECT_ZKBUILDER_ZKBUILDEROPS_H_

#include "lib/Dialect/ZKBuilder/ZKBuilderDialect.h"
#include "lib/Dialect/ZKBuilder/ZKBuilderTypes.h"
#include "lib/Dialect/ZKExpr/ZKExprTypes.h"
#include "mlir/Interfaces/InferTypeOpInterface.h" // from @llvm-project
#include "mlir/include/mlir/IR/BuiltinOps.h"      // from @llvm-project
#include "mlir/include/mlir/IR/BuiltinTypes.h"    // from @llvm-project
#include "mlir/include/mlir/IR/Dialect.h"         // from @llvm-project

#define GET_OP_CLASSES
#include "lib/Dialect/ZKBuilder/ZKBuilderOps.h.inc"

#endif // LIB_DIALECT_ZKBUILDER_ZKBUILDEROPS_H_
