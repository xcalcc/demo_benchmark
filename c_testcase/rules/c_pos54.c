//
// detect and handle posix lib errors
//

#include <stdio.h>
#include <string.h>
  
int main(int argc, char *argv[]) {
  FILE *out;
  FILE *in;
  size_t size;
  char *ptr;
  
  if (argc != 2) {
    /* Handle error */
  }
  
  in = fmemopen(argv[1], strlen(argv[1]), "r"); // "in" is not checked 
  /* Use in */
  
  out = open_memstream(&ptr, &size);
  /* Use out */
  
  return 0;
}

