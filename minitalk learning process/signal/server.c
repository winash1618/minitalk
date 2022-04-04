/* This is program p1. */
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

/* Ssshhh! Global variables!  We need
   these so that main() and sh1 & sh2
   can communicate. */
char sym = 'X';
FILE *fp = NULL;

void sh1(int st)
{
  signal(SIGUSR1,sh1);
  fscanf(fp,"%c",&sym);
}

void sh2(int st)
{
	 signal(SIGUSR1,sh1);
  fp = fopen("foo","r");
  setbuf(fp,NULL);
}

int main()
{
  /* Register signal handlers. */
  signal(SIGUSR1,sh1);
	signal(SIGUSR2,sh2);
  /* Print sym forever: Uncomment the stuff below if you
                        are running this remotely! */
  setbuf(stdout,NULL);
  /*struct timespec T, D; T.tv_sec = 0; T.tv_nsec = 5000000;*/
  printf("%d", getpid());
  printf("%c", sym);
  while(1)
    pause();
	
  return 0;

}