// RUN: zklean-opt %s > %t
// RUN FileCheck %s < %t

module {
  // CHECK-LABEL: test_op_syntax
  func.func @test_op_syntax(%arg0 : !ZKExpr.zkexpr,
                            %arg1 : !ZKExpr.felt
                           ) {
    %1 = ZKExpr.Add %arg0 %arg0
    %2 = ZKExpr.Sub %1 %arg0
    %3 = ZKExpr.Mul %2 %1

    %6 = ZKExpr.Literal %arg1

    return
  }
}
