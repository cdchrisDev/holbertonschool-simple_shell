# Everything you need to know to start coding your own shell
# PID & PPID
A process is an instance of a executing program, that has a unique ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process' ID: `man 2 getpid`
```
julien@ubuntu:~/c/shell$ cat pid.c
#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Werror -pedantic pid.c -o mypid && ./mypid
3237
julien@ubuntu:~/c/shell$ ./mypid 
3238
julien@ubuntu:~/c/shell$ ./mypid 
3239
julien@ubuntu:~/c/shell$ 
```
**NOTE**: every time you run your program, create a new instance. So your ID process is unique.<br />
Each process has a parent: the process that created it. to get the PID of a parent process check `man 2 getppid`
# Exercises
## 0. getppid
write a program that prints the **PID** of the parent process. Run your program several times within the same shell. It should be the same. Does `echo $$` print the same value? why?
```
#include <stdio.h>
#include <unistd.h>
/**
 * get_PPID - a simple getppid function
 * @void: NA
 * Return: parent id
 */
int main(void)
{
        pid_t getPPID;

        getPPID = getppid();
        printf("My parent process ID is: %u\n", getPPID);
        return (0);
}
```
## 1. /proc/sys/kernel/pid_max
Write a shell script that prints the maximun value a process ID can be
```
#!/bin/bash
cat /proc/sys/kernel/file-max
```
# Arguments
The command line arguments are passed through the `main` function: `int main(int ac, char **av);`
* `av` is a `NULL` terminated array of strings
* `ac` is the number of items in `av`
`av[0]` usually contains the name used to invoke the current program. `av[1]` is the first argument of the program, `av[2]` the second and so on.
# Exercise
## 0.av
