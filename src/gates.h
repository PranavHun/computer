#ifndef __GATES_H
#define __GATES_H
#include "transistor.h"
#include <stdbool.h>

void gate_and(bool input1, bool input2, bool *output);
void gate_or(bool input1, bool input2, bool *output);
void gate_not(bool input, bool *output);
void gate_nand(bool input1, bool input2, bool *output);
void gate_nor(bool input1, bool input2, bool *output);
void gate_xor(bool input1, bool input2, bool *output);
void gate_xnor(bool input1, bool input2, bool *output);
#endif