# minitalk

## Functions allowed.

### signal
  - As a pre requisite first we will learn about what is fork system call and wait system call.
    - fork system call : fork(),  Fork system call is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process). It takes no parameters and returns an integer value. Below are different values returned by fork(). for more details : https://www.geeksforgeeks.org/fork-system-call/
      - Negative Value: creation of a child process was unsuccessful.
      - Zero: Returned to the newly created child process.
      - Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
    - wait system call : wait(), A call to wait() blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction. For more details : https://www.geeksforgeeks.org/wait-system-call-c/
