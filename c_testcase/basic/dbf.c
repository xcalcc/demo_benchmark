#include <stdio.h>
#include <stdlib.h>


void func_1(void *p) {
  if (p != NULL) {
    free(p);   /* free p */
  }
}

int func_2(void *p) {
  if (p != NULL) {
    free(p);  /* free p */
  }
  // no return here. Rule: MSC37-C. while func_1() not
}

int test_DBF() {
  int i, *p, *q;
  p = malloc(10 * sizeof(int));
  if (p == NULL)
    return 1;
  for (i=0; i < 10; ++i)
    p[i] = i;

  q = p;
  func_1(p);  /* free p the first time */
  func_2(q);  /* free p the second time. Double Free */

  return 0;
}

int main()
{
	return test_DBF();
}
