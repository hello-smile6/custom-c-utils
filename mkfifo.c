#include <stdio.h>
#include "sysexits-polyfill.h"
#include <stdlib.h>
#include <sys/stat.h>
#include "common.h"
int main ( int argc, char *argv[] )
{
  /* Make sure sysexits.h is available */
    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
      /* We print argv[0] assuming it is the program name */
      fprintf(stderr, "usage: %s filename\n", argv[0] );
      exit(EX_USAGE);
    }
    else 
    {
      unsigned int fifoResult=mkfifo(argv[1], 0666);
      if ( ( fifoResult ) != 0 ) {
        if( fifoResult  == -1 ) {
          fprintf(stderr, "mkfifo() failed with filename %s: file exists\n", argv[2]);
        }
        fprintf(stderr, "mkfifo() syscall with filename %s failed with error %d\n", argv[2], fifoResult);
        exit(EX_OSERR);
      }
      else {
        exit(EX_OK);
      }
    }
    }