#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void test_uaf() {
  int i, j, *p, *q;
  p = malloc(10 * sizeof(int));
  if (p == NULL)
    return;
  for (i = 0; i < 10; ++i)
    p[i] = i;
  q = p;
  uaf_free(p);    /* p is freed here */
  j = 0;
  for (i = 0; i < 10; ++i)
    j += q[i];    /* try to dereference p */
  printf("value of j = %d\n", j);
}

