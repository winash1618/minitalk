#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv)
{
  /* Get p1's process ID. */
  pid_t pid = atoi(argv[1]);

  /* Open foo for unbuffered writing. */
  FILE *fp = fopen("foo","w");
  setbuf(fp,NULL);

  /* Tell p1 to open foo. */
  kill(pid,SIGUSR2);

  /* Read char, write to foo, notify p1. */
  char c;
  while(scanf("%c",&c) == 1)
  {
    if (c == '\n') continue;
    fprintf(fp,"%c",c);
    kill(pid,SIGUSR1);
  }

  /* Delete file foo & kill p1. */
  unlink("foo");
  kill(pid,SIGTERM);

  return 0;
}