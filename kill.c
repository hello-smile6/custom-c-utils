#include "common.h"
#include <stdlib.h>
#include <stdio.h>
/* Make sure this works */
#undef _SIGNAL_H
#define __USE_POSIX
#include "signal-wrapper.h"
#include <unistd.h>
#include <sys/types.h>
#include <sysexits.h>
#include <sys/signal.h>
int main( int argc, char *argv[] ) {
  if(argc!=2) {
    printf("What should we kill?\n");
    exit(1);
  }
  else {
    char * blankString;
    int pid=strtol(argv[1], &blankString, 10);
    int killResult=kill(pid, 15);
    if(killResult==0) {
      exit(0);
    }
    else {
      exit(1);
    }
  }
}