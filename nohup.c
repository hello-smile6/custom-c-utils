 /*
  * This implementation of nohup exits immediately on the main thread.
  * 
  */
#include <stdlib.h>
#include <unistd.h>
int main( int argc, char *argv[] ) {
  #ifndef __MINGW32__
  if(argc == 2) {
    int forkResult;
    forkResult=fork();
    if(forkResult==0) {
      int childProcess=system(argv[1]);
      exit(childProcess);
    }
    else {
      if(forkResult<=-1) {
        exit(-1);
      }
      exit(0);
    }
  }
  else {
    exit(-1);
  }
  #endif
  #ifdef __MINGW32__
  printf("Windows is not supported.\n\tIf you know how to make fork() work on Windows, open a pull request!\n");
  exit(0);
  #endif
}