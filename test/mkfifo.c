/* Don't fail on Windows, just add an error */
#ifndef __MINGW32__
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
  int fifoUnlink=unlink("test/test-fifo");
  if(fifoUnlink==0) {
    printf("Named pipe unlink succeeded. (Initializing)\n");
  }
  int mkfifoCall=system("out/mkfifo test/test-fifo");
  if(mkfifoCall>0) {
    fprintf(stderr, "mkfifo failed!\n");
    exit(1);
  }
  else {
    printf("mkfifo succeeded!\n");
  }
  struct stat buffer;
int fifoStat=stat("test/test-fifo", &buffer);
  if(fifoStat==0) {
    printf("mkfifo successfully created a named pipe!\n");
  }
  else {
    printf("Looks like our named pipe's missing...\n");
    exit(1);
  }
  printf("Cleaning up...\n");
  int finalUnlink=unlink("test/test-fifo");
  if(finalUnlink == 0) {
    printf("Unlinked our named pipe!\n");
  }
  else {
    printf("Failed to unlink our named pipe\n");
    exit(1);
  }
  exit(0);
}
#endif
#ifdef __MINGW32__
#include <stdio.h>
int main() {
  printf("mkfifo() is unsupported on Windows, exiting with status 0 anyway (to avoid failing builds).");
  exit(0);
}
#endif