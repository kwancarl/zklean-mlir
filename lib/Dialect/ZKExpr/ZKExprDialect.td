#ifndef LIB_DIALECT_ZKEXPR_ZKEXPRDIALECT_TD_
#define LIB_DIALECT_ZKEXPR_ZKEXPRDIALECT_TD_

include "mlir/IR/OpBase.td"

def ZKExpr_Dialect : Dialect {
  let name = "ZKExpr";
  let summary = "A dialect for zkexpr";
  let description = [{
    The zkexpr dialect defines types and operations for 
    ZK Expressions and ZK Builders.
  }];

  let cppNamespace = "::mlir::zkexpr";

  let useDefaultTypePrinterParser = 1;
}

#endif  // LIB_DIALECT_ZKEXPR_ZKEXPRDIALECT_TD_
