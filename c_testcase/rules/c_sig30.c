//
// only call async-safe functions with signal handlers
// For strict conformance, 
// abort(), _Exit(), quick_exit(), and signal() can be safely called from signal handlers
// see CETT-C Rule 11 SIG30-C for full list of POSIX async signal-safe for complete list
//



#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


enum { MAXLINE = 1024 };
char *info = NULL;


void log_msg(void)
{
  fputs(info, stderr);
}


void handler(int signum)
{
  log_msg();  // this call will end up calling fputs, also not allowed
  free(info); // should not call free here
  info = NULL;
}


int c_sig30(void)
{
  if (signal(SIGINT, handler) == SIG_ERR) {
    printf("signal error\n");
    exit(1);
  }
  info = (char *)malloc(MAXLINE);
  if (info == NULL) {
    printf("malloc error\n");
    exit(1);
  }

  while (1) {
    log_msg();
  }
  return 0;
}

