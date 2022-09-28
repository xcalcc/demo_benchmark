//
// do not call "system()"
// can be exploited to execute arbitrary system commands
// further check on unsanitized command string from tainted source
// explicit or relative path when a command specifies a path enables attacker to
// take over cwd resulting in sensitive data exposure
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 
enum { BUFFERSIZE = 512 };
 
void c_env33(const char *input) {
  char cmdbuf[BUFFERSIZE];
  int len_wanted = snprintf(cmdbuf, BUFFERSIZE,
                            "any_cmd '%s'", input);
  if (len_wanted >= BUFFERSIZE) {
    /* Handle error */
  } else if (len_wanted < 0) {
    /* Handle error */
  } else if (system(cmdbuf) == -1) {
    /* Handle error */
  }
}

