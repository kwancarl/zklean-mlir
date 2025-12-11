set(LLVM_TARGET_DEFINITIONS ZKBuilderOps.td)
mlir_tablegen(ZKBuilderOps.h.inc -gen-op-decls)
mlir_tablegen(ZKBuilderOps.cpp.inc -gen-op-defs)
mlir_tablegen(ZKBuilderTypes.h.inc -gen-typedef-decls -typedefs-dialect=zkbuilder)
mlir_tablegen(ZKBuilderTypes.cpp.inc -gen-typedef-defs -typedefs-dialect=zkbuilder)
mlir_tablegen(ZKBuilderDialect.h.inc -gen-dialect-decls -dialect=zkbuilder)
mlir_tablegen(ZKBuilderDialect.cpp.inc -gen-dialect-defs -dialect=zkbuilder)
add_public_tablegen_target(MLIRZKBuilderOpsIncGen)
add_dependencies(mlir-headers MLIRZKBuilderOpsIncGen)

add_mlir_doc(ZKBuilderDialect ZKBuilderDialect ZKBuilder/ -gen-dialect-doc)

add_mlir_dialect_library(MLIRZKBuilder
    ZKBuilderDialect.cpp
    ZKBuilderOps.cpp

    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/lib/Dialect/ZKBuilder

    LINK_LIBS PUBLIC
    )
