# resources
  - https://stackoverflow.com/questions/6768426/in-a-signal-handler-how-to-know-where-the-program-is-interrupted
  - http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html
  - https://www.gnu.org/software/libc/manual/html_node/Processes.html Read it inorder to get understanding of processes
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L01/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L02/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L03/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L04/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L05/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L06/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L07/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L08/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L09/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L10/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L11/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L12/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L13/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L14/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L15/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L16/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L20/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L21/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L22/Class.html
  - https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L23/Class.html
  - http://catb.org/esr/writings/taoup/html/ch02s01.html 
  - https://people.cs.rutgers.edu/~pxk/416/notes/c-tutorials/
  - https://programmerah.com/10-signals-14273/
  - http://www.haifux.org/guy_keren.html

# Signals
  - Signals are primarily used by the operating system to signal to processes that something has happened that probably needs some attention. 
  - It could also be used in between processes or even inside a process to raise an exception.
  - If you open a shell you can list all possible signals by using the command kill. As you see there are quite many, but don't be afraid, you do not have to learn them by heart.
  ```
  kill -l
  ```
  - You might have used the kill command when you wanted to kill a process but the command will be able to send any signal to a process. When no signal is given the SIGTERM signal is sent to the process. 
  - You might have learned to write kill -9 when you really wanted to kill something; what is signal number 9 called? Ans. SIGKILL
  
## Sending Signals Using The Keyboard
  - The most common way of sending signals to processes is using the keyboard. There are certain key presses that are interpreted by the system as requests to send signals to the process with which we are interacting:
  - Ctrl-C : Pressing this key causes the system to send an INT signal (SIGINT) to the running process. By default, this signal causes the process to immediately terminate.
  - Ctrl-Z : Pressing this key causes the system to send a TSTP signal (SIGTSTP) to the running process. By default, this signal causes the process to suspend execution.
  - Ctrl-\ : Pressing this key causes the system to send a ABRT signal (SIGABRT) to the running process. By default, this signal causes the process to immediately terminate. Note that this redundancy (i.e. Ctrl-\ doing the same as Ctrl-C) gives us some better flexibility. We'll explain that later on.

## Default Signal Handlers
  - If you install no signal handlers of your own (remember what a signal handler is? yes, that function handling a signal?), the runtime environment sets up a set of default signal handlers for your program. For example, the default signal handler for the TERM signal calls the exit() system call. The default handler for the ABRT signal calls the abort() system call, which causes the process's memory image to be dumped into a file named 'core' in the process's current directory, and then exit.

## Sending Signals From The Command Line
  - Another way of sending signals to processes is done using various commands, usually internal to the shell:
    - kill : The kill command accepts two parameters: a signal name (or number), and a process ID. Usually the syntax for using it goes something like:
    ```
      kill -<signal> <PID>
    ```
    - For example, in order to send the INT signal to process with PID 5342, type:
    ```
      kill -INT 5342
    ```  
    - This has the same affect as pressing Ctrl-C in the shell that runs that process.
  - If no signal name or number is specified, the default is to send a TERM signal to the process, which normally causes its termination, and hence the name of the kill command.
    ```
      fg
    ```
    - On most shells, using the 'fg' command will resume execution of the process (that was suspended with Ctrl-Z), by sending it a CONT signal.

## Signal Types
  - There in total 31 type of signals in sys/signal.h file. (in our 42 Mac) (you can check it by vs code)
  - On Linux system For more details goto : http://www.cs.kent.edu/~ruttan/sysprog/lectures/signal.7.html

## Sending Signals Using System Calls
  - A third way of sending signals to processes is by using the kill system call. This is the normal way of sending a signal from one process to another. This system call is also used by the 'kill' command or by the 'fg' command. Here is an example code that causes a process to suspend its own execution by sending itself the STOP signal:
    ```
      #include <unistd.h>     /* standard unix functions, like getpid()       */
      #include <sys/types.h>  /* various type definitions, like pid_t         */
      #include <signal.h>     /* signal name macros, and the kill() prototype */

      /* first, find my own process ID */
      pid_t my_pid = getpid();

      /* now that i got my PID, send myself the STOP signal. */
      kill(my_pid, SIGSTOP); //return value is int
    ```
  - An example of a situation when this code might prove useful, is inside a signal handler that catches the TSTP signal (Ctrl-Z, remember?) in order to do various tasks before actually suspending the process. We will see an example of this later on.

## Catchable And Non-Catchable Signals
  - Most signals may be caught by the process, but there are a few signals that the process cannot catch, and cause the process to terminate. For example, the KILL signal (-9 on all unices I've met so far) is such a signal. This is why you usually see a process being shut down using this signal if it gets "wild". One process that uses this signal is a system shutdown process. It first sends a TERM signal to all processes, waits a while, and after allowing them a "grace period" to shut down cleanly, it kills whichever are left using the KILL signal.
  - STOP is also a signal that a process cannot catch, and forces the process's suspension immediately. This is useful when debugging programs whose behavior depends on timing. Suppose that process A needs to send some data to process B, and you want to check some system parameters after the message is sent, but before it is received and processed by process B. One way to do that would be to send a STOP signal to process B, thus causing its suspension, and then running process A and waiting until it sends its oh-so important message to process B. Now you can check whatever you want to, and later on you can use the CONT signal to continue process B's execution, which will then receive and process the message sent from process A.
  - Now, many other signals are catchable, and this includes the famous SEGV and BUS signals. You probably have seen numerous occasions when a program has exited with a message such as 'Segmentation Violation - Core Dumped', or 'Bus Error - core dumped'. In the first occasion, a SEGV signal was sent to your program due to accessing an illegal memory address. In the second case, a BUS signal was sent to your program, due to accessing a memory address with invalid alignment. In both cases, it is possible to catch these signals in order to do some cleanup - kill child processes, perhaps remove temporary files, etc. Although in both cases, the memory used by your process is most likely corrupt, it's probable that only a small part of it was corrupt, so cleanup is still usually possible.

## Catching Signals - Signal Handlers
  - Inorder catch a signal that is being send to the by any of the above three ways, we need signal handlers.
  - A signal handler is just a function that you compile together with the rest of the program. Instead of directly invoking the function, you use signal or sigaction to tell the operating system to call it when a signal arrives. This is known as establishing/installing the handler.
  - 
## Installing Signal Handlers
  - There are several ways to install signal handlers. Here we going to focus on mainly two.
    - signal()
    - sigaction()

### signal()
  - The signal() system call is used to set a signal handler for a single signal type. signal() accepts a signal number and a pointer to a signal handler function, and sets that handler to accept the given signal. As an example, here is a code snippest that causes the program to print the string "Don't do that" when a user presses Ctrl-C:

  ```
    sighandler_t signal(int signum, sighandler_t handler);
  ```
  - Let’s look at how signal is implemented:
  ```
    #include <stdio.h>     /* standard I/O functions                         */
    #include <unistd.h>    /* standard unix functions, like getpid()         */
    #include <signal.h>    /* signal name macros, and the signal() prototype */

    /* first, here is the signal handler */
    void catch_int(int sig_num)
    {
        /* re-set the signal handler again to catch_int, for next time */
        signal(SIGINT, catch_int);
        printf("Don't do that\n");
        fflush(stdout);
    }

    int main(int argc, char* argv[])
    {
        /* set the INT (Ctrl-C) signal handler to 'catch_int' */
        signal(SIGINT, catch_int);

        /* now, lets get into an infinite loop of doing nothing. */
        for ( ;; )
            pause();
    }
  ```
### sigaction()
  - The “signal facility is a simplified interface to the more general sigaction facility.” Indeed, when we trace a C program with signal calls, we only see calls to sigaction system calls. We’re also told that “signal is less portable than sigaction when establishing a signal handler”. Let’s look into sigaction. It’s a system call. It has a more complicated interface than signal:
    ```
    int sigaction(int signum, const struct sigaction *restrict act,
                     struct sigaction *restrict oldact);
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
  - Data Type: sigset_t (used to represent a signal set. Internally, it may be implemented as either an integer or structure type.) 
  - The “mask” is a sigset_t, which is a set of signal numbers. The mask for signal sig expresses which signals the process can receive while it is handling signal number sig.
  - Let’s look at how sigaction is implemented:
    ```
      #include <stdio.h>
      #include <signal.h>
      #include <unistd.h>
      int volatile count ;
      void handler(int sig) 
      {
        printf("signal %d ouch that hurt\n",sig);
        count++;
      }
      int main ( ) 
      {
        struct sigaction sa ;
        int pid = getpid() ;
        printf("ok,let's go,kill me(%d) if you can!\n",pid);
        sa.sa_handler=handler;
        sa.sa_flags=0;
        sigemptyset(&sa.sa_mask);
        if(sigaction(SIGINT,&sa,NULL)!=0){
        return(1);
      }
        while(count!=4)
        {
        }
        printf("I'vehadenough!\n");
        return(0);
      }
    ```
## Pending Signals
  - There is a brief period of time between the time a signal is generated and the time a signal is delivered (i.e. the action for the signal is taken). If another signal in generated during this time problems can arise. For instance you might wish to reset the signal handler but before the signal handler is reset another signal could arrive.

## sigset_t : a datatype
  - There are two ways to initialize a signal set. You can initially specify it to be empty with sigemptyset and then add specified signals individually. Or you can specify it to be full with sigfillset and then delete specified signals individually.
  - You must always initialize the signal set with one of these two functions before using it in any other way. Don’t try to set all the signals explicitly because the sigset_t object might include some other information (like a version field) that needs to be initialized as well. (In addition, it’s not wise to put into your program an assumption that the system has no signals aside from the ones you know about.)
  - initializing with sigemptyset()
    - Function: This function initializes the signal set set to exclude all of the defined signals. It always returns 0.
      ```
        int sigemptyset (sigset_t *set)
      ```
    - for example:
      ```
        struct sigaction sa;
        sigemptyset(&sa.sa_mask);
      ```
  - initializing with sigfillset()
    - Function : This function initializes the signal set set to include all of the defined signals. Again, the return value is 0.
      ```
        int sigfillset (sigset_t *set)
      ```
  - sigaddset and sigdelset adds and deletes signal from the signal set.

    
