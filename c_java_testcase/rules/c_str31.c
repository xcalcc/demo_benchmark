#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//
// STR31 -   Guarantee that storage for strings has sufficient space
//           for character data and the null character
// Severity  High
// Priority  P18    (highest)
// Likelihood    Likely
//
// Related CVE - 2009-1252
//               2009-0587
//
// Equivalent CWE 2.11 - 119, 120, 123, 125, 676
//
void get_passwd(void)
{
  char buf[256];
  char *passwd = getenv("PASSWORD");
  if (passwd == NULL) {
    printf("Error getting password\n");
    exit(1);
  }
  //
  // copy environmental string to a fixed-length can cause buffer overflow
  //
  strcpy(buf, passwd);
}

