#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void test_dbf() {
  int i, *p, *q;
  p = malloc(10 * sizeof(int));
  if (p == NULL)
    return;
  for (i=0; i < 10; ++i)
    p[i] = i;
  q = p;          /* q now points to p's memory block */
  dbf_free_1(p);  /* p is freed the first time */
  dbf_free_2(q);  /* p is freed the second time */
}

