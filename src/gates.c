#include "gates.h"

void gate_and(bool input1, bool input2, bool *output) {
  bool t1_collector = false;
  bool t1_emittor = false;
  transistor(true, input1, &t1_collector, &t1_emittor);
  bool t2_V = t1_emittor;
  bool t2_collector = t1_collector;
  bool t2_emittor = false;
  transistor(t2_V, input2, &t2_collector, &t2_emittor);
  bool t3_base = t2_collector;
  bool t3_V = true;
  bool t3_emittor = false;
  transistor(t3_V, t3_base, output, &t3_emittor);
}

void gate_or(bool input1, bool input2, bool *output) {
  bool t1_collector = false, t1_emittor = false;
  transistor(true, input1, &t1_collector, &t1_emittor);
  bool t2_collector = false, t2_emittor = false;
  transistor(t1_collector, input2, &t2_collector, &t2_emittor);
  *output = t1_emittor + t2_emittor;
}

void gate_not(bool input, bool *output) {
  bool t_emittor;
  transistor(true, input, output, &t_emittor);
}

void gate_nand(bool input1, bool input2, bool *output) {
  gate_and(input1, input2, output);
  gate_not(*output, output);
}

void gate_nor(bool input1, bool input2, bool *output) {
  gate_or(input1, input2, output);
  gate_not(*output, output);
}

void gate_xor(bool input1, bool input2, bool *output) {
  bool output_nand, output_or;
  gate_nand(input1, input2, &output_nand);
  gate_or(input2, input1, &output_or);
  gate_and(output_nand, output_or, output);
}

void gate_xnor(bool input1, bool input2, bool *output) {
  gate_xor(input1, input2, output);
  gate_not(*output, output);
}
