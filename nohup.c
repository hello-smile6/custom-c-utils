 /*
  * This implementation of nohup exits immediately on the main thread.
  * 
  */
#include <stdlib.h>
#include <unistd.h>
int main( int argc, char *argv[] ) {
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
}