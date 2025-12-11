#ifndef LIB_DIALECT_ZKEXPR_ZKEXPRTYPES_TD_
#define LIB_DIALECT_ZKEXPR_ZKEXPRTYPES_TD_

// Path hack to get ZKExpr types included into ZKBuilder
include "../ZKExpr/ZKExprDialect.td"
include "mlir/IR/AttrTypeBase.td"

// TODO: Consider if all types need to be paramerterized by field f like in
// zkexpr

// A base class for all types in this dialect
// class ZKExpr_Type<string name, string typeMnemonic> : TypeDef<ZKExpr_Dialect, name> {
//  let mnemonic = typeMnemonic;
//}


def Felt : TypeDef<ZKExpr_Dialect, "Felt"> {
  let summary = "Field element";
  let mnemonic = "felt";
  let description = [{
        Field element
  }];
}

// In zkExpr this is just an abbr for nat
def WitnessID: TypeDef<ZKExpr_Dialect, "WitnessID"> {
  let summary = "WitnessID";
  let mnemonic = "Witnessid";
  let description = [{
    WitnessID
  }];
}

def ZKExpr : TypeDef<ZKExpr_Dialect, "ZKExpr"> {
  let summary = "ZKExpr for things";
  let mnemonic = "zkexpr";
  let description = [{
    A type for zkExpr.
  }];
}

def ComposedLookupTable : TypeDef<ZKExpr_Dialect, "ComposedLookupTable"> {
  let summary = "Lookup table parameterized by table dimensions";
  let mnemonic = "composedlookuptable";
  let description = [{
        Lookup table parameterized by table dimensions
  }];

  // TODO: See zkexpr/.../AST.expr and update params when clarified
  let parameters = (ins "int":$cols, "int":$rows);
  let assemblyFormat = "`<` $cols $rows `>`";
}

#endif  // LIB_DIALECT_ZKEXPR_ZKEXPRTYPES_TD_
