set(LLVM_TARGET_DEFINITIONS ZKExprOps.td)
mlir_tablegen(ZKExprOps.h.inc -gen-op-decls)
mlir_tablegen(ZKExprOps.cpp.inc -gen-op-defs)
mlir_tablegen(ZKExprTypes.h.inc -gen-typedef-decls -typedefs-dialect=zkexpr)
mlir_tablegen(ZKExprTypes.cpp.inc -gen-typedef-defs -typedefs-dialect=zkexpr)
mlir_tablegen(ZKExprDialect.h.inc -gen-dialect-decls -dialect=zkexpr)
mlir_tablegen(ZKExprDialect.cpp.inc -gen-dialect-defs -dialect=zkexpr)
add_public_tablegen_target(MLIRZKExprOpsIncGen)
add_dependencies(mlir-headers MLIRZKExprOpsIncGen)

add_mlir_doc(ZKExprDialect ZKExprDialect ZKExpr/ -gen-dialect-doc)

add_mlir_dialect_library(MLIRZKExpr
    ZKExprDialect.cpp
    ZKExprOps.cpp

    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/lib/Dialect/ZKExpr

    LINK_LIBS PUBLIC
    )
