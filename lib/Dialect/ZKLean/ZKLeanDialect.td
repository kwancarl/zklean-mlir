#ifndef LIB_DIALECT_ZKLEAN_ZKLEANDIALECT_TD_
#define LIB_DIALECT_ZKLEAN_ZKLEANDIALECT_TD_

include "mlir/IR/OpBase.td"

def ZKLean_Dialect : Dialect {
  let name = "zklean";
  let summary = "A dialect for zklean";
  let description = [{
    The zklean dialect defines types and operations for 
    ZK Expressions and ZK Builders.
  }];

  let cppNamespace = "::mlir::zklean";

  let useDefaultTypePrinterParser = 1;
}

#endif  // LIB_DIALECT_ZKLEAN_ZKLEANDIALECT_TD_
