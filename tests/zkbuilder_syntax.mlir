// RUN: zklean-opt %s > %t
// RUN FileCheck %s < %t

module {
  // CHECK-LABEL: test_op_syntax
  func.func @test_op_syntax(%arg0 : !ZKExpr.zkexpr,
                            %arg1 : !ZKExpr.zkexpr,
                            %arg2 : !ZKExpr.zkexpr
                           ) {
    %1 = ZKExpr.Add %arg0 %arg0
    %2 = ZKExpr.Sub %1 %arg0
    %3 = ZKExpr.Mul %2 %1

    // TODO: Figure out how to do add checks properly
    // CHECK: zkbuilder.ConstrainEq
    %4 = zkbuilder.ConstrainEq %2 %1
    // CHECK: zkbuilder.ConstrainR1CS
    %5 = zkbuilder.ConstrainR1CS %3 %2 %1

    return
  }
}
