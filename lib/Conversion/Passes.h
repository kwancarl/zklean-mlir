#ifndef LIB_CONVERSION_PASSES_H
#define LIB_CONVERSION_PASSES_H

#include <memory>

#include "mlir/Pass/Pass.h"

namespace mlir {
class Pass;

namespace zklean {

/// Creates a template conversion pass that rewrites zkLean operations to
/// MLIR's core dialects (arith, etc.). Replace the placeholder logic inside
/// `ConvertZKLeanToArith.cpp` when real conversions are known.
std::unique_ptr<Pass> createConvertZKLeanToArithPass();

/// Creates a template conversion pass for lowering zkLean into the LLZK
/// dialects. This is a scaffold only; hook up real type converters and rewrite
/// patterns in `ConvertZKLeanToLLZK.cpp`.
std::unique_ptr<Pass> createConvertZKLeanToLLZKPass();

/// Registers all zkLean conversion passes with MLIR's pass registry so they can
/// be invoked from tools like `zklean-opt`.
void registerZKLeanConversionPasses();

} // namespace zklean
} // namespace mlir

#endif // LIB_CONVERSION_PASSES_H
