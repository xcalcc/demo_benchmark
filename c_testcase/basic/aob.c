#include <stdio.h>

int assign_AOB(int* a, int i)
{
  return a[i];  /* called by main
                   a only has 2 elements but i is 2 */
}

int test_AOB() {
  int a[2] = {0, 1}, b;
  b = assign_AOB(a, 2);  /* call assign with a and i
                        a has two elements and i is 2
                        a[2] is out-of-bound and also uninitialized */
  printf("value of b = %d\n", b);
  return 0;
}

int main()
{
	return test_AOB();
}

