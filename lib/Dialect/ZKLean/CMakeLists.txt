set(LLVM_TARGET_DEFINITIONS ZKLeanOps.td)
mlir_tablegen(ZKLeanOps.h.inc -gen-op-decls)
mlir_tablegen(ZKLeanOps.cpp.inc -gen-op-defs)
mlir_tablegen(ZKLeanTypes.h.inc -gen-typedef-decls -typedefs-dialect=zklean)
mlir_tablegen(ZKLeanTypes.cpp.inc -gen-typedef-defs -typedefs-dialect=zklean)
mlir_tablegen(ZKLeanDialect.h.inc -gen-dialect-decls -dialect=zklean)
mlir_tablegen(ZKLeanDialect.cpp.inc -gen-dialect-defs -dialect=zklean)
add_public_tablegen_target(MLIRZKLeanOpsIncGen)
add_dependencies(mlir-headers MLIRZKLeanOpsIncGen)

add_mlir_doc(ZKLeanDialect ZKLeanDialect ZKLean/ -gen-dialect-doc)

add_mlir_dialect_library(MLIRZKLean
    ZKLeanDialect.cpp
    ZKLeanOps.cpp

    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/lib/Dialect/ZKLean

    LINK_LIBS PUBLIC
    )
