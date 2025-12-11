// RUN: zklean-opt %s > %t
// RUN FileCheck %s < %t

module {
  // CHECK-LABEL: test_op_syntax
  func.func @test_op_syntax(%arg0 : !zkexpr.zkexpr,
                            %arg1 : !zkexpr.felt
                           ) {
    // CHECK: zkexpr.Add
    %1 = zkexpr.Add %arg0 %arg0
    // CHECK: zkexpr.Sub
    %2 = zkexpr.Sub %1 %arg0
    // CHECK: zkexpr.Mul
    %3 = zkexpr.Mul %2 %1

    // CHECK: zkexpr.Literal
    %6 = zkexpr.Literal %arg1

    return
  }
}
