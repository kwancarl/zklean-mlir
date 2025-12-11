#ifndef LIB_DIALECT_ZKBUILDER_ZKBUILDERDIALECT_TD_
#define LIB_DIALECT_ZKBUILDER_ZKBUILDERDIALECT_TD_

include "mlir/IR/OpBase.td"

def ZKBuilder_Dialect : Dialect {
  let name = "zkbuilder";
  let summary = "A dialect for zkbuilder";
  let description = [{
    The zkbuilder dialect defines types and operations for 
    ZK Builderessions and ZK Builders.
  }];

  let cppNamespace = "::mlir::zkbuilder";

  let useDefaultTypePrinterParser = 1;
}

#endif  // LIB_DIALECT_ZKBUILDER_ZKBUILDERDIALECT_TD_
