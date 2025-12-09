#ifndef LIB_DIALECT_ZKLEAN_ZKLEANOPS_H_
#define LIB_DIALECT_ZKLEAN_ZKLEANOPS_H_

#include "lib/Dialect/ZKLean/ZKLeanDialect.h"
#include "lib/Dialect/ZKLean/ZKLeanTypes.h"
#include "mlir/Interfaces/InferTypeOpInterface.h" // from @llvm-project
#include "mlir/include/mlir/IR/BuiltinOps.h"      // from @llvm-project
#include "mlir/include/mlir/IR/BuiltinTypes.h"    // from @llvm-project
#include "mlir/include/mlir/IR/Dialect.h"         // from @llvm-project

#define GET_OP_CLASSES
#include "lib/Dialect/ZKLean/ZKLeanOps.h.inc"

#endif // LIB_DIALECT_ZKLEAN_ZKLEANOPS_H_
