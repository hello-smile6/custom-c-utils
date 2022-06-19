#include "common.h"
#include <stdlib.h>
#include <stdio.h>
int main( int argc, char *argv[] ) {
  if(argc!=2) {
    printf("What should we kill?\n");
    exit(1);
  }
  else {
    char * blankString;
    int pid=strtol(argv[1], &blankString, 10);
    kill(pid, 15);
  }
}