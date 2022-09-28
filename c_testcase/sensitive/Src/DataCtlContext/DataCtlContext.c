#include <stdio.h>

int assign(int* a, int i)
{
  return a[i];
}

void DataCtlContext() {
  int a[2] = {0, 1}, b,c;
  int array1[10]={0,1,2,3,4,5,6,7,8,9};

  b = assign(a, 2);  /* call assign with a and i
                        a has two elements and i is 2
                        a[2] is out-of-bound and also uninitialized */
  c = assign(a, 1);

  printf("value of b = %d\n", b);
  printf("value of c = %d\n", c); 
  printf("value of assign(array1,2) = %d\n", assign(array1,2));
  printf("value of assign(a,2) = %d\n", assign(a,2));
 
  int i=0;
  for(i=0;i<2;i++)
  {
      b = assign(a,i);
      printf("value of b = %d\n", b);
  }
}

int main()
{
  DataCtlContext();
  return 0;
}

