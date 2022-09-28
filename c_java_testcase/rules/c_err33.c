//
// Dectect and handle standard library errors
//

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
int utf8_to_wcs(wchar_t *wcs, size_t n, const char *utf8,
                size_t *size) {
  if (NULL == size) {
    return -1;
  }
  char *result = setlocale(LC_CTYPE, "en_US.UTF-8");
  printf("%s\n", result); // result is not detected
  *size = mbstowcs(wcs, utf8, n);
  return 0;
}

