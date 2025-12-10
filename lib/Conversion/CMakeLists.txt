add_mlir_conversion_library(MLIRZKLeanConversion
    ConvertZKLeanToLLZK.cpp
    Passes.cpp
    ZKLeanConversion.cpp

    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/lib/Conversion

    LINK_LIBS PUBLIC
    MLIRArithDialect
    MLIRIR
    MLIRPass
    MLIRTransforms
    MLIRZKLean
)

target_include_directories(MLIRZKLeanConversion PRIVATE
    ${PROJECT_SOURCE_DIR}/externals/llzk-lib/include
)
