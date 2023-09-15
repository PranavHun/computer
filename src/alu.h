#ifndef __ALU_H
#define __ALU_H
#include "gates.h"
#include <stdbool.h>
void decoder(bool f0, bool f1, bool *out1, bool *out2, bool *out3, bool *out4);
void logic_unit(bool A, bool B, bool *out1, bool *out2, bool *out3);
void full_adder(bool A, bool B, bool carry_in, bool *output, bool *carry_out);
void alu_1bit(bool A, bool B, bool carry_in, bool f0, bool f1, bool *output,
              bool *carry_out);
void alu(bool f0, bool f1, bool A[8], bool B[8], bool *output, bool *carry);
#endif