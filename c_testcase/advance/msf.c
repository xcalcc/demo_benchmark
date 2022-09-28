#include <stdio.h>
#include <stdlib.h>
#include "global.h"

void test_msf() {
  int *p;
  struct S *s;
  p = malloc(10 * sizeof(int));
  if (p == NULL)
    return;
  s = (struct S*)malloc(sizeof(struct S));
  if (s == NULL) {
    free(p);
    return;
  }
  s->p = p;
  msf_free(s);  /* only s is freed,
                   s->p is not */
}

