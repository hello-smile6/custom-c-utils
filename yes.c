#include <stdio.h>
#include <string.h>
#include "common.h"
#include <stdlib.h>
int main(  int argc, char *argv[] ) {
  char *yesValue;
  yesValue="y";
  if((argc) == 2) {
    if(strcmp(argv[1], "--help") == 0) {
      printf("%s", VER_HEADER);
      exit(0);
    }
    else {
      if(strcmp(argv[1],"--version") == 0) {
        printf("%s\n", CUTILS_VERSION);
        exit(0);
      }
      execYes(argv[1]);
    }
  }
  else {
    if((argc) == 1) {
      execYes("y");
    }
  }
  exit(1);
}
int execYes( char *yesValue ) {
  while(1) {
    /* setvbuf(stdout, NULL, _IONBF, 0); */
    /* fflush(stdout); */
    printf("%s\n", yesValue);
    /* Flush stdout */
  };
}
