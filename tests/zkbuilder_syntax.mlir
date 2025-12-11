// RUN: zklean-opt %s > %t
// RUN FileCheck %s < %t

module {
  // CHECK-LABEL: test_op_syntax
  func.func @test_op_syntax(%arg0 : !zkexpr.zkexpr,
                            %arg1 : !zkexpr.zkexpr,
                            %arg2 : !zkexpr.zkexpr
                           ) {
    // CHECK: zkexpr.Add
    %1 = zkexpr.Add %arg0 %arg0
    // CHECK: zkexpr.Sub
    %2 = zkexpr.Sub %1 %arg0
    // CHECK: zkexpr.Mul
    %3 = zkexpr.Mul %2 %1

    // TODO: Figure out how to do add checks properly
    // CHECK: zkbuilder.ConstrainEq
    %4 = zkbuilder.ConstrainEq %2 %1
    // CHECK: zkbuilder.ConstrainR1CS
    %5 = zkbuilder.ConstrainR1CS %3 %2 %1

    return
  }
}
