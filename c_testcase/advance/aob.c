#include <stdio.h>
#include "global.h"

void test_aob() {
  int a[2] = {0, 1}, b;
  b = aob_assign(a, 2);  /* call aob_assign with a and 2
                            a only has two elements and 
                            2 is out of range */
  printf("value of b = %d\n", b);
}

