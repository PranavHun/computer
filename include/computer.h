#ifndef __COMPUTER_H_
#define __COMPUTER_H_
#include <stdbool.h>

void gate_and(bool input1, bool input2, bool *output);
void gate_or(bool input1, bool input2, bool *output);
void gate_not(bool input, bool *output);
void gate_nand(bool input1, bool input2, bool *output);
void gate_nor(bool input1, bool input2, bool *output);
void gate_xor(bool input1, bool input2, bool *output);
void gate_xnor(bool input1, bool input2, bool *output);

void alu(bool f0, bool f1, bool A[8], bool B[8], bool *output, bool *carry);
#endif