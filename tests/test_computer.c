#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/computer.h"

int test_gate_2input(void (*gate_func)(bool, bool, bool *),
                     bool test_matrix[][4]) {
  bool output;
  for (int i = 0; i < 4; ++i) {
    gate_func(test_matrix[i][0], test_matrix[i][1], &output);
    if (output != test_matrix[i][2])
      return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int test_gate_1input(void (*gate_func)(bool, bool *), bool test_matrix[][2]) {
  bool output;
  for (int i = 0; i < 2; ++i) {
    gate_func(test_matrix[i][0], &output);
    if (output != test_matrix[i][1])
      return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void dec_to_binary(uint8_t dec, bool *binary) {
  for (int i = 0; i < 8; i++) {
    binary[7 - i] = dec & (1 << i) ? 1 : 0;
  }
}

void binary_to_dec(bool *binary, bool carry, uint16_t *dec) {
  uint16_t two_power = 1;
  for (int i = 0; i < 8; i++) {
    *dec += binary[7 - i] * two_power;
    two_power *= 2;
  }
  *dec += carry * (two_power * 2);
}

int test_alu(bool f0, bool f1, uint8_t A, uint8_t B, uint16_t test_output) {
  uint16_t output;
  bool A_binary[8], B_binary[8], Output_binary[9], carry;
  dec_to_binary(A, A_binary);
  dec_to_binary(B, B_binary);
  alu(f0, f1, A_binary, B_binary, Output_binary, &carry);
  binary_to_dec(Output_binary, carry, &output);
  if (output == test_output)
    return EXIT_SUCCESS;
  else
    return EXIT_FAILURE;
}

int main(int argc, char *argv[]) {
  int selection;
  if (argc > 1)
    selection = atoi(argv[1]);

  switch (selection) {
  case 0:
    return test_gate_2input(gate_and, (bool[][4]){{false, false, false},
                                                  {false, true, false},
                                                  {true, false, false},
                                                  {true, true, true}});
  case 1:
    return test_gate_2input(gate_or, (bool[][4]){{false, false, false},
                                                 {false, true, true},
                                                 {true, false, true},
                                                 {true, true, true}});
  case 2:
    return test_gate_1input(gate_not,
                            (bool[][2]){{false, true}, {true, false}});
  case 3:
    return test_gate_2input(gate_nand, (bool[][4]){{false, false, true},
                                                   {false, true, true},
                                                   {true, false, true},
                                                   {true, true, false}});
  case 4:
    return test_gate_2input(gate_nor, (bool[][4]){{false, false, true},
                                                  {false, true, false},
                                                  {true, false, false},
                                                  {true, true, false}});
  case 5:
    return test_gate_2input(gate_xor, (bool[][4]){{false, false, false},
                                                  {false, true, true},
                                                  {true, false, true},
                                                  {true, true, false}});

  case 6:
    return test_gate_2input(gate_xnor, (bool[][4]){{false, false, true},
                                                   {false, true, false},
                                                   {true, false, false},
                                                   {true, true, true}});
  case 7:
    return test_alu(0, 0, 124, 45, 131);
  case 8:
    return test_alu(0, 1, 124, 45, 44);
  case 9:
    return test_alu(1, 0, 124, 45, 125);
  case 10:
    return test_alu(1, 1, 124, 45, 169);
  }

  return 0;
}
