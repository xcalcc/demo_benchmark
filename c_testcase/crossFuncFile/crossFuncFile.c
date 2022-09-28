#include <stdio.h>

int assign_npd(int* a);

int crossFuncFile() {
  int *a=NULL, b;
  b = assign_npd(a);  /* call assign with NULL pointer
                     dereference a in assign is a
                     Null-Pointer-Dereference issue */
  printf("value of b = %d\n", b);
  return 0;
}

int main()
{
  return crossFuncFile();
}
