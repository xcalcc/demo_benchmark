//
// use readlink() properly
// symbolic link filled by readlink in its second arg is not null filled
//

#include <unistd.h>
#include <fcntl.h>

void c_pos30(){
  char buf[1024];
  ssize_t len = readlink("/usr/bin/perl", buf, sizeof(buf)); // AOB due to sizeof(buf)
  buf[len] = '\0';
  return;
}

