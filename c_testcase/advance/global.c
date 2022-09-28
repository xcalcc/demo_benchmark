#include <stdio.h>
#include <stdlib.h>
#include "global.h"

int aob_assign(int* a, int i)
{
  return a[i];  /* called by test_aob
                   a only has twp elements and
                   i is 2 */
}

void dbf_free_1(void *p) {
  if (p != NULL) {
    free(p);    /* called by test_dbf
                   p is freed here */
  }
}

void dbf_free_2(void *p) {
  if (p != NULL) {
    free(p);    /* called by test_dbf
                   p is freed here */
  }
}

void msf_free(struct S* s) {
  if (s != NULL)
    free(s);    /* called by test_msf
                   s is freed here
                   s->p isn't freed */
}

int npd_assign(int* a)
{
  return *a;    /* called by test_npd
                   return dereference of a
                   if a is NULL, this is a
                   Null-Pointer-Dereference issue */
}

void uaf_free(void *p) {
  if (p != NULL)
    free(p);    /* called by test_uaf
                   p is freed here */
}

int uiv_assign(int* a)
{
  return *a;    /* called by test_uiv
                   return derefence of a
                   if a is not NULL but *a isn't assigned
                   this is a Un-Initialuzed Variable use issue */
}


