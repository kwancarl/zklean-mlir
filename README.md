# zkLean MLIR Dialect

This repository contains an [MLIR](https://mlir.llvm.org/) dialect for zkLean.
[zkLean](https://github.com/GaloisInc/zk-lean) is a domain specific language
(DSL) for specifying zero-knowledge statements in the Lean theorem prover. This
dialect is intended to interface with
[LLZK](https://github.com/Veridise/llzk-lib) (WIP).

## Prerequisites

*   A C++ compiler
*   [LLVM / MLIR](https://llvm.org/docs/GettingStarted.html#software), 
*   [Ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages)


## Build and test

While standing in `zklean-mlir/`, run

```bash
bash build_deps.sh
bash build_test.sh
```

The first command will build MLIR, assuming the LLVM project source is placed
in `zklean-mlir/externals/`. The second command will build `zklean-opt` and run
tests. These commands have succeeded on x86 machines running Debian and NixOS.
Please inspect `build_deps.sh`, `build_test.sh`, and `CMakeLists.txt` and
modify to point to your `llvm-project/` directory (or as needed).


## Warning 
Work in progress

## See also

* [MLIR standalone example](https://github.com/llvm/llvm-project/tree/main/mlir/examples/standalone)
* [MLIR-tutorial](https://github.com/j2kun/mlir-tutorial)
