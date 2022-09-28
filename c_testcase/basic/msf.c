#include <stdio.h>
#include <stdlib.h>

struct S {
  int *p;
};

int test_MSF() {
  int *p;
  struct S *s;
  p = malloc(10 * sizeof(int));

  if (p == NULL)
    return 1;

  s = (struct S*)malloc(sizeof(struct S));

  if (s == NULL) {
    free(p);
    return 1;
  }
  s->p = p;
  free(s);    /* only s is freed
                 s->p isn't. MSF here*/
  return 0;
}

int main()
{
    return test_MSF();
}

