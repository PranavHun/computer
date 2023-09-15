#include "transistor.h"

void transistor(bool V, bool base, bool *collector, bool *emittor) {
  if (base) {
    if (V) {
      *collector = false;
      *emittor = true;
    } else {
      *collector = true;
      *emittor = false;
    }
  } else {
    if (V) {
      *collector = true;
      *emittor = false;
    } else {
      *emittor = false;
    }
  }
}
