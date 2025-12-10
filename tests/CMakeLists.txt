configure_lit_site_cfg(
    ${CMAKE_CURRENT_SOURCE_DIR}/lit.cmake.site.cfg.py.in
    ${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py
    MAIN_CONFIG
    ${CMAKE_CURRENT_SOURCE_DIR}/lit.cmake.cfg.py
)

# MLIR Tutorial tests from mlir-tutorial, used as santiy check, remove later
set (MLIR_TUTORIAL_TEST_DEPENDS
    FileCheck count not
    mlir-opt
    mlir-runner
)

set (ZKLEAN_TEST_DEPENDS
    zklean-opt
)

add_lit_testsuite(check-mlir-tutorial "Running the MLIR tutorial regression tests"
    ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${MLIR_TUTORIAL_TEST_DEPENDS}
    ARGS -j 1
)

add_lit_testsuite(check-zklean-opt "Running the ZKLean tests"
    ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${ZKLEAN_TEST_DEPENDS}
    ARGS -j 1
)
