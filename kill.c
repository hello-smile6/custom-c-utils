#ifndef __MINGW32__
#include "common.h"
#include <stdlib.h>
#include <stdio.h>
/* Make sure this works */
#undef _SIGNAL_H
#define __USE_POSIX
#include "signal-wrapper.h"
#include <unistd.h>
#include "sysexits-polyfill.h"
#include <sys/types.h>
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
#endif
#ifdef __MINGW32__
#include <stdio.h>
/*
  * https://github.com/hello-smile6/custom-c-utils/runs/6958933775?check_suite_focus=true#step:3:13
  * Make sure we don't have that issue
  */
#include <stdlib.h>
int main() {
  printf("kill() is unsupported on Windows.");
  exit(1);
}
#endif