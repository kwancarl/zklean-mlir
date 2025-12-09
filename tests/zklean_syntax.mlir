// RUN: zklean-opt %s > %t
// RUN FileCheck %s < %t

module {
  // CHECK-LABEL: test_op_syntax
  func.func @test_op_syntax(%arg0 : !zklean.zkexpr,
                            %arg1 : !zklean.felt,
                            %arg2 : !zklean.witnessid
                           ) {
    // CHECK: zklean.Add
    %1 = zklean.Add %arg0 %arg0
    // CHECK: zklean.Sub
    %2 = zklean.Sub %1 %arg0
    // CHECK: zklean.Mul
    %3 = zklean.Mul %2 %1


    // CHECK: zklean.ConstrainEq
    %4 = zklean.ConstrainEq %2 %1
    // CHECK: zklean.ConstrainR1CS
    %5 = zklean.ConstrainR1CS %3 %2 %1

    // CHECK: zklean.Literal
    %6 = zklean.Literal %arg1

    // CHECK: zklean.WitnessVar
    %7 = zklean.WitnessVar %arg2

    // CHECK: zklean.Witnessable.witness
    %8 = zklean.Witnessable.witness

    return
  }
}
