#ifndef LIB_DIALECT_ZKLEAN_ZKLEANTYPES_TD_
#define LIB_DIALECT_ZKLEAN_ZKLEANTYPES_TD_

include "ZKLeanDialect.td"
include "mlir/IR/AttrTypeBase.td"

// TODO: Consider if all types need to be paramerterized by field f like in
// zklean

// A base class for all types in this dialect
// class ZKLean_Type<string name, string typeMnemonic> : TypeDef<ZKLean_Dialect, name> {
//  let mnemonic = typeMnemonic;
//}


def Felt : TypeDef<ZKLean_Dialect, "Felt"> {
  let summary = "Field element";
  let mnemonic = "felt";
  let description = [{
        Field element
  }];
}

// In zkLean this is just an abbr for nat
def WitnessID: TypeDef<ZKLean_Dialect, "WitnessID"> {
  let summary = "WitnessID";
  let mnemonic = "witnessid";
  let description = [{
    WitnessID
  }];
}

def ZKExpr : TypeDef<ZKLean_Dialect, "ZKExpr"> {
  let summary = "ZKExpr for things";
  let mnemonic = "zkexpr";
  let description = [{
    A type for zkExpr.
  }];
}

def ComposedLookupTable : TypeDef<ZKLean_Dialect, "ComposedLookupTable"> {
  let summary = "Lookup table parameterized by table dimensions";
  let mnemonic = "composedlookuptable";
  let description = [{
        Lookup table parameterized by table dimensions
  }];

  // TODO: See zklean/.../AST.lean and update params when clarified
  let parameters = (ins "int":$cols, "int":$rows);
  let assemblyFormat = "`<` $cols $rows `>`";
}

def ZKBuilderState : TypeDef<ZKLean_Dialect, "ZKBuilderState"> {
  let summary = "State of the ZKBuilder";
  let mnemonic = "zkbuilderstate";
  let description = [{
        State of the ZKBuilder
  }];
}


/*
def ZKField : ZKLean_Type<"ZKField", "zklean"> {
  let summary = "";

  let description = [{
    A type for ...
  }];

  // let assemblyFormat = "`<` hiya_there `>`";
}
*/

#endif  // LIB_DIALECT_ZKLEAN_ZKLEANTYPES_TD_
