//
// all exit handlers must return normally
//


#include <stdlib.h>
#include <stdio.h>

void exit1(void)
{
  printf("inside exit1\n");
  return;
}

int some_cond;

void exit2(void)
{

  if (some_cond) {
    printf("inside exit2 cond\n");
    exit(0);   // this causes atexit to have different behavior on different paths
  }
  printf("inside exit2\n");
  return;
}


int c_env32(void)
{
  if (atexit(exit1) != 0) {
    printf("error calling atexit_exit1\n");
  }
  if (atexit(exit2) != 0) {
    printf("error calling atexit_exit2\n");
  }
  return 0;
}

