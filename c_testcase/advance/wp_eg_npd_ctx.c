#include "global.h"

int global;

int *another_func(int offset, int r)
{
  int *q = 0;
  int i;

  for (i=0; i<100; i++) {
    if (r != 10) {
      r++;
      q = &global;
    }
  }
  return q;
}


int npd_cross_func_ctx(int random_val, int *p, int offset)
{
  if (offset != 0) {
    p = another_func(offset, random_val);
  }
  #if 0
  else {
    p = another_func(0, 20);
  }
  #endif
  
  return *p;
}


