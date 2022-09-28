//
// do not call putenv with a pointer to a local as arg
// the pointer will be put into the environment array
// the problem will be similar to return address of local
//

#include <stdlib.h>
#include <stdio.h>

int c_pos34(const char *var) {
  char env[1024];
  int retval = snprintf(env, sizeof(env),"TEST=%s", var);
  if (retval < 0 || (size_t)retval >= sizeof(env)) {
    /* Handle error */
  }
 
  return putenv(env); // local env may be freed
}

