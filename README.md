# minitalk

## Functions allowed.

### signal
  - As a pre requisite first we will learn about what is fork system call and wait system call.
    - fork system call : fork(),  Fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process). It takes no parameters and returns an integer value. Below are different values returned by fork(). for more details : https://www.geeksforgeeks.org/fork-system-call/
      - Negative Value: creation of a child process was unsuccessful.
      - Zero: Returned to the newly created child process.
      - Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
    - wait system call : wait(), A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction. For more details : https://www.geeksforgeeks.org/wait-system-call-c/
 - A signal is a software generated interrupt that is sent to a process by the OS because of when user press ctrl-c or another process tell something to this process. There are fix set of signals that can be sent to a process. signal are identified by integers. Signal number have symbolic names. For example: 
```
  #define SIGHUP  1   /* Hangup the process */ 
  #define SIGINT  2   /* Interrupt the process */ 
  #define SIGQUIT 3   /* Quit the process */ 
  #define SIGILL  4   /* Illegal instruction. */ 
  #define SIGTRAP 5   /* Trace trap. */ 
  #define SIGABRT 6   /* Abort. */
```
  - For each process, the operating system maintains 2 integers with the bits corresponding to a signal numbers.
  - The two integers keep track of: pending signals and blocked signals 
  - With 32 bit integers, up to 32 different signals can be represented.
  - Sending signals via kill() : 
```
int kill(pid_t pid, int signal);
pid: id of destination process
signal: the type of signal to send
Return value: 0 if signal was sent successfully
```
  - let's look at how signal is implemented.
```
// allows for a signal to be caught, to be ignored, or to generate an interrupt
sig_t signal(int sig, sig_t handler) {

    // Construct the new disposition
    struct sigaction newDisp;
    newDisp.sa_handler = handler;
    sigemptyset(&newDisp.sa_mask);
    newDisp.sa_flags = SA_RESTART;

    // We'll put the old disposition here
    struct sigaction prevDisp;

    if (sigaction(sig, &newDisp, &prevDisp) == -1) {
      return SIG_ERR;
    } else {
      // User of signal doesn't care about the whole disposition; just the handler
      return prevDisp.sa_handler;
    }
}
```
  - For more details : https://www.geeksforgeeks.org/signals-c-language/    https://jameshfisher.com/2017/01/13/c-sigaction/#:~:text=sigaction(sig%2C%20act%2C%20oact,the%20given%20signal%20is%20received

##sigaction()
  - The “signal facility is a simplified interface to the more general sigaction facility.” Indeed, when we trace a C program with signal calls, we only see calls to sigaction system calls. We’re also told that “signal is less portable than sigaction when establishing a signal handler”.
  - Let’s look into sigaction. It’s a system call. It has a more complicated interface than signal:
```
#include <signal.h>
int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
```
  - sigaction(sig, act, oact) means “set the disposition for sig to act, and store the old disposition in oact”. Its return value is 0 or -1, indicating whether the system call errored.
  - Those struct sigactions are “dispositions”, meaning they express what to do when the given signal is received. The disposition consists of a handler, a mask, and some flags:
```
struct sigaction {
 union __sigaction_u __sigaction_u;  /* signal handler */
 sigset_t sa_mask;               /* signal mask to apply */
 int     sa_flags;               /* see signal options below */
};
```
- The “mask” is a sigset_t, which is a set of signal numbers. The mask for signal sig expresses which signals the process can receive while it is handling signal number sig.
##sigemptyset()
  - Initializes a signal set set to the empty set. All recognized signals are excluded. 
  - sigemptyset() is part of a family of functions that manipulate signal sets. Signal sets are data objects that let a process keep track of groups of signals. For example, a process can create one signal set to record which signals it is blocking, and another signal set to record which signals are pending. 
  - Signal sets are used to manipulate groups of signals used by other functions (such as sigprocmask()) or to examine signal sets returned by other functions (such as sigpending()).
  - If successful, sigemptyset() returns 0.
```
#define _POSIX_SOURCE
#include <signal.h>
int sigemptyset(sigset_t *set);
```
  
    

