#include <stdio.h>
#include "global.h"

void test_uiv() {
  int a, b;
  b = uiv_assign(&a);  /* try to read a which is uninitialized */
  printf("value of b = %d\n", b);
}

