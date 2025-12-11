#ifndef LIB_DIALECT_ZKEXPR_ZKEXPROPS_H_
#define LIB_DIALECT_ZKEXPR_ZKEXPROPS_H_

#include "lib/Dialect/ZKExpr/ZKExprDialect.h"
#include "lib/Dialect/ZKExpr/ZKExprTypes.h"
#include "mlir/Interfaces/InferTypeOpInterface.h" // from @llvm-project
#include "mlir/include/mlir/IR/BuiltinOps.h"      // from @llvm-project
#include "mlir/include/mlir/IR/BuiltinTypes.h"    // from @llvm-project
#include "mlir/include/mlir/IR/Dialect.h"         // from @llvm-project

#define GET_OP_CLASSES
#include "lib/Dialect/ZKExpr/ZKExprOps.h.inc"

#endif // LIB_DIALECT_ZKEXPR_ZKEXPROPS_H_
