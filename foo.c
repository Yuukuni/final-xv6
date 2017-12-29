//foo.c

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int  k, n, pid;
  double x = 0,  z;

  if(argc < 2 )
    n = 1;       //default value
  else
    n = atoi ( argv[1] ); //from command line
  if ( n < 0 || n > 20 )
    n = 2;
  x = 0;
  pid = 0;
  for ( k = 0; k < n; k++ ) {
    pid = fork();
    if ( pid < 0 ) {
      printf(1, "%d failed in fork!\n", getpid() );
    } else if ( pid > 0 ) {  //parent
      printf(1, "Parent %d creating child %d\n", getpid(), pid );
   } else {   // child
      printf(1, "Child %d created\n",getpid() );
      for ( z = 0; z < 8000000.0; z += 0.001 )
       x =  x + 3.14 * 89.64;   // useless calculations to consume CPU time
      break;
    }
  }
  
  exit();
}
