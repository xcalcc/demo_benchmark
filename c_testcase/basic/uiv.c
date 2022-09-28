#include <stdio.h>

int assign_UIV(int* a)
{
  return *a;  /* dereference a */
}

int test_UIV() {
  int a, b;
  b = assign_UIV(&a);  /* call assign with a uninitialized */
  printf("value of b = %d\n", b);
  return 0;
}

int main()
{
	return test_UIV();
}
