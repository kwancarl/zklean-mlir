#ifndef LIB_DIALECT_ZKLEAN_ZKLEANOPS_TD_
#define LIB_DIALECT_ZKLEAN_ZKLEANOPS_TD_

include "ZKLeanDialect.td"
include "ZKLeanTypes.td"
include "mlir/IR/BuiltinAttributes.td"
include "mlir/IR/OpBase.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

// TODO: Separate ZKExpr and ZKBuilder into two different dialects


class ZKExpr_BinOp<string mnemonic> : Op<ZKLean_Dialect, mnemonic, [Pure, ElementwiseMappable, SameOperandsAndResultType]> {
  let arguments = (ins ZKExpr:$lhs, ZKExpr:$rhs);
  let results = (outs ZKExpr:$output);
  let assemblyFormat = "$lhs $rhs attr-dict";
}

def ZKExpr_AddOp : ZKExpr_BinOp<"Add"> {
  let summary = "Addition operation between ZK Expressions.";
}

def ZKExpr_SubOp : ZKExpr_BinOp<"Sub"> {
  let summary = "Subtraction operation between ZK Expressions.";
}

def ZKExpr_MulOp : ZKExpr_BinOp<"Mul"> {
  let summary = "Multiplication operation between ZK Expressions.";
}


def ZKLean_LiteralOp : Op<ZKLean_Dialect, "Literal", [Pure]> {
  let summary = "Introduce ZK literal";
  let arguments = (ins Felt:$literal);
  let results = (outs ZKExpr:$output);
  let assemblyFormat = "$literal attr-dict";
}

def ZKLean_WitnessVarOp : Op<ZKLean_Dialect, "WitnessVar", [Pure]> {
  let summary = "Introduce witness variable";
  let arguments = (ins WitnessID:$id);
  let results = (outs ZKExpr:$output);
  let assemblyFormat = "$id attr-dict";
}

// TODO: Figure out the difference between Builder witness, zkexpr witness, and
// witnessable.witness
def ZKLean_WitnessOp : Op<ZKLean_Dialect, "Witnessable.witness", [Pure, ConstantLike]> {
  let summary = "Witnessable.witness";
  let results = (outs ZKExpr:$output);
  let assemblyFormat = "attr-dict";
}

/*
def ZKLean_LiteralOp : Op<ZKLean_Dialect, "literal", [Pure, ConstantLike]> {
  let summary = "Define a literal.";
  let arguments = (ins AnyIntElementsAttr:$literal);
  let results = (outs ZKExpr:$output);
  let assemblyFormat = "$literal attr-dict";
  // let hasFolder = 1;
}

def ZKLean_ConstantOp : Op<ZKLean_Dialect, "constant", [Pure, ConstantLike]> {
  let summary = "Define a constant zk expression .";
  let arguments = (ins AnyIntElementsAttr:$constant);
  let results = (outs ZKExpr:$output);
  let assemblyFormat = "$constant attr-dict `:` qualified(type($output))";
  let hasFolder = 1;
}
*/



////////////////////////////////////////////////////////
//        ZKBuilderOps
////////////////////////////////////////////////////////

def ZKBuilder_ConstrainEqOp : Op<ZKLean_Dialect, "ConstrainEq", [Pure]> {
  let summary = "Constrain two ZK Expressions to be equal";
  let arguments = (ins ZKExpr:$lhs, ZKExpr:$rhs);
  let results = (outs ZKBuilderState:$output);
  let assemblyFormat = "$lhs $rhs attr-dict";
}

def ZKBuilder_ConstrainR1CSOp : Op<ZKLean_Dialect, "ConstrainR1CS", [Pure]> {
  let summary = "Constrain R1CS in the Builder State";
  let arguments = (ins ZKExpr:$a, ZKExpr:$b, ZKExpr:$c);
  let results = (outs ZKBuilderState:$output);
  let assemblyFormat = "$a $b $c attr-dict";
}

/*
def ZKLean_WitnessVarOp : Op<ZKLean_Dialect, "WitnessVar", [Pure, ConstantLike] {
  let summary = "Introduce ZK witness variable";
  let arguments = (ins AnyIntElementsAttr:$lit);
  let results = (outs ZKExpr:$output)
}
*/
#endif  // LIB_DIALECT_ZKLEAN_ZKLEANOPS_TD_
