#include "alu.h"

void decoder(bool f0, bool f1, bool *out1, bool *out2, bool *out3, bool *out4) {
  bool output_not1, output_not2;
  gate_not(f0, &output_not1);
  gate_not(f1, &output_not2);

  gate_and(output_not1, output_not2, out1);
  gate_and(output_not2, f0, out2);
  gate_and(output_not1, f1, out3);
  gate_and(f1, f0, out4);
}

void logic_unit(bool A, bool B, bool *out1, bool *out2, bool *out3) {
  gate_not(A, out1);
  gate_or(A, B, out2);
  gate_and(A, B, out3);
}

void full_adder(bool A, bool B, bool carry_in, bool *output, bool *carry_out) {
  bool output_xor, output_and1, output_and2;
  gate_xor(A, B, &output_xor);
  gate_xor(carry_in, output_xor, output);
  gate_and(A, B, &output_and1);
  gate_and(output_xor, carry_in, &output_and2);
  gate_or(output_and2, output_and1, carry_out);
}

void alu_1bit(bool A, bool B, bool carry_in, bool f0, bool f1, bool *output,
              bool *carry_out) {
  bool output_decoder[4];
  bool output_logic_unit[3];
  bool output_full_adder;
  decoder(f0, f1, &output_decoder[0], &output_decoder[1], &output_decoder[2],
          &output_decoder[3]);
  logic_unit(A, B, &output_logic_unit[0], &output_logic_unit[1],
             &output_logic_unit[2]);
  full_adder(A, B, carry_in, &output_full_adder, carry_out);

  bool output_and[4];

  gate_and(output_logic_unit[0], output_decoder[0], &output_and[0]);
  gate_and(output_logic_unit[1], output_decoder[1], &output_and[1]);
  gate_and(output_logic_unit[2], output_decoder[2], &output_and[2]);
  gate_and(output_decoder[3], output_full_adder, &output_and[3]);

  bool output_xor[2];
  gate_xor(output_and[0], output_and[1], &output_xor[0]);
  gate_xor(output_and[2], output_and[3], &output_xor[1]);
  gate_xor(output_xor[0], output_xor[1], output);
}

void alu(bool f0, bool f1, bool A[8], bool B[8], bool *output, bool *carry) {
  for (int i = 7; i >= 0; --i) {
    alu_1bit(A[i], B[i], *carry, f0, f1, &output[i], carry);
  }
}
