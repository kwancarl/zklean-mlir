get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)

set (LIBS
    ${dialect_libs}
    ${conversion_libs}
    MLIROptLib
    
    # Comment out following two lines if MLIRRegisterAll<x> is not found when
    # build_test.sh
    MLIRRegisterAllDialects
    MLIRRegisterAllPasses

    MLIRZKLean
    MLIRZKLeanConversion
    # ortools::ortools
)

add_llvm_executable(zklean-opt zklean-opt.cpp)

llvm_update_compile_flags(zklean-opt)
target_link_libraries(zklean-opt PRIVATE ${LIBS})

mlir_check_all_link_libraries(zklean-opt)
