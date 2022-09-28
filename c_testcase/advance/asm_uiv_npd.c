#include "global.h"

int asm_add(int a) {
  int b;
  int c = a;
  asm ("add %1, %0\n" : "+r"(c) : "r"(b));
  return c;
}

int asm_deref(int *p) {
  int c;
  asm ("mov (%1), %0" : "=r"(c) : "p"(p));
  return c;
}

int foo() {
  return asm_deref(0);
}

