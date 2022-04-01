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
  
    

