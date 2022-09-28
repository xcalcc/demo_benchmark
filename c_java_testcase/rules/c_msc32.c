//
// Properly seed pseudorandom number generators
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
void c_msc32(void) {
  unsigned int i;
  struct timespec ts;
  if (timespec_get(&ts, TIME_UTC) == 0) {
    if (timespec_get(&ts, TIME_UTC) == 1)
      srandom(ts.tv_nsec ^ ts.tv_sec);
  }
  else {
    if (timespec_get(&ts, TIME_UTC) == 2)
      srandom(ts.tv_nsec ^ ts.tv_sec);
  }
  for (i = 0; i < 10; ++i) {
    /* Generates different sequences at different runs */
    printf("%ld, ", random()); // not all the path call srandom first
  }
}

void wrong(void) {
  unsigned int i;
  for (i = 0; i < 10; ++i) {
    /* Generates different sequences at different runs */
    printf("%ld, ", random()); // not all the path call srandom first
  }
}
