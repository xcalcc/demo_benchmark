#include <stdio.h>
#include "global.h"

void test_npd() {
  int *a = NULL, b;
  b = npd_assign(a);   /* try to dereference a which is NULL */
  printf("value of b = %d\n", b);
}

