#include <stdio.h>

int assign_NPD(int* a)
{
  return *a;  /* dereference a */
}

int test_NPD() {
  int *a = NULL, b;
  b = assign_NPD(a);  /* call assign with NULL pointer
                     dereference a in assign_NPD is a
                     Null-Pointer-Dereference issue */
  printf("value of b = %d\n", b);
  return 0;
}

int main()
{
	return test_NPD();
}

