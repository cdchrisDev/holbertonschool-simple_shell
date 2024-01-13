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
## 0.av
write a program that prints all the arguments, without using ac
```
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(int ac, char **av)
{
        int i = 1;
        (void)ac;

        while (av[i++] != NULL)
                printf("%s ", av[i]);

        putchar('\n');
}
```
## 1. Read line
Write a program that prints "$ ", wait for the user to enter a command, prints it on the next line.
`man 3 getline`

**important** make sure you read the man, and the **RETURN VALUE** section, in order to know when to stop reading Keyword: “end-of-file”, or `EOF` (or `Ctrl+D`).

**advanced**: Write your own version of `getline`.
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
        char *bf = NULL;
        size_t len = 0;

        printf("$ ");
        getline(&bf, &len, stdin);

        printf("your input is: %s\n and the size is %ld\n", bf, len);

        free(bf);
}
```
## 2. command line to av
Write a function that splits a string and returns an array of each word of the string.
`man strtok`
**advance**: Write the function without
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void)
{
        char c[] = "Hola como estas";
        char d[] = " ";
        char *p;

        p = strtok(c, d);

        while (p != NULL)
        {
                printf("%s", p);
                p = strtok (NULL, d);
        }

        putchar('\n');
}
```
# Executing a program
The system call `execve` allows a process to execute another program `man 2 execve`. Note that this system call does load the new program into the current process' memory in place of the "previous" program: on success `execve` does not return to continue the rest of the "previous" program.<br />

**Warning**: In this example, `execve` is used without the current environment (last argument), don't forget to add it in your Shell!
```
julien@ubuntu:~/c/shell$ cat exec.c
#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic exec.c -o exec
julien@ubuntu:~/c/shell$ ./exec 
Before execve
total 120
drwxr-xr-x   2 root root 61440 Dec  4 00:08 bin
drwxr-xr-x   2 root root  4096 Jul 19 13:47 games
drwxr-xr-x  58 root root  4096 Oct 27 13:10 include
drwxr-xr-x 138 root root  4096 Dec  4 00:08 lib
drwxr-xr-x   3 root root  4096 Nov 10 09:54 lib32
drwxr-xr-x   3 root root  4096 Nov 10 09:54 libx32
drwxr-xr-x  10 root root  4096 Jul 19 13:42 local
drwxr-xr-x   3 root root  4096 Jul 19 13:48 locale
drwxr-xr-x   2 root root 12288 Dec  2 11:03 sbin
drwxr-xr-x 295 root root 12288 Jul 27 08:58 share
drwxr-xr-x   6 root root  4096 Dec  1 11:39 src
julien@ubuntu:~/c/shell$ 
```
# Creating processes 
The system call `fork` (`man 2 fork`) creates a new child process, almost identical to the parent (the process that calls `fork`). Once `fork` successfully returns, two processes continue to run the same program, but with different stacks, datas and heaps.
```
julien@ubuntu:~/c/shell$ cat fork.c
#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t pid;

    printf("Before fork\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return (1);
    }
    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    return (0);
}
julien@ubuntu:~/c/shell$ ./fork 
Before fork
After fork
My pid is 4819
julien@ubuntu:~/c/shell$ After fork
My pid is 4820
```
**Note**: the is no typo in the above example<br />
Using the return value of `fork`, it is possible to know if the current process is the father or the child: `fork` will return `0` to the child, and the PID of the child to the father
```
julien@ubuntu:~/c/shell$ cat fork.c
#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    if (child_pid == 0)
    {
        printf("(%u) Nooooooooo!\n", my_pid);
    }
    else
    {
        printf("(%u) %u, I am your father\n", my_pid, child_pid);
    }
    return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic fork.c -o fork
julien@ubuntu:~/c/shell$ ./fork 
My pid is 4869
(4869) 4870, I am your father
julien@ubuntu:~/c/shell$ My pid is 4870
(4870) Nooooooooo!
```
# Wait
The wait system call (`man 2 wait`) suspends execution of the calling process until one of its children terminates.
```
julien@ubuntu:~/c/shell$ cat wait.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
        printf("Wait for me, wait for me\n");
        sleep(3);
    }
    else
    {
        wait(&status);
        printf("Oh, it's all better now\n");
    }
    return (0);
}
julien@ubuntu:~/c/shell$ gcc -Wall -Wextra -Werror -pedantic wait.c -o wait
julien@ubuntu:~/c/shell$ ./wait 
Wait for me, wait for me
Oh, it's all better now
julien@ubuntu:~/c/shell$ 
```
## Exercise: fork + wait + execve
Write a program that execute command `ls -l /tmp` in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.<br />
´´´
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
        pid_t MyPid;
        pid_t getid;
        int status;

        getid = getpid(); /* tell me who processes */
        printf("before fork I was one: I identify as %u, and that means chris.\n", getid);
        MyPid = fork(); /* new process */
        wait(&status); /* wait until process ends */
        if (MyPid == -1)
        {       /* check new process return success*/
                perror("Error:");
                return (1);
        }
        /* checking process status*/
        getid = getpid();
        if (MyPid == 0)
                printf("After fork I'm another,now %u. I grew up so much I became the child.\n", getid);
        else
                printf("I returned to the father, cuz I'm chris again (%u) \n", getid);

        MyPid = fork();
        if (MyPid == 0)
        {
                wait(&status);
                MyPid = fork();

                static char *newarg[] = { "/bin/ls", "-l", "/tmp", NULL};
                static char *newEnviron[] = { NULL };

                if (argc != 2)
                {
                        fprintf(stderr, "Usage %s <file-to-exec>\n", argv[0]);
                        exit(EXIT_FAILURE);
                }
                newarg[0] = argv[1];
                wait(&status);

                execve(argv[1], newarg, newEnviron);
        }
        else
        {
                fork();
                printf("I'm your father\n");
                wait(&status);
        }
        return (0);
}
´´´
## Exercise: super simple shell
using everything we saw, write a first version of a super simple shell that can run commands with their full path, without using any argument
```
julien@ubuntu:~/c/shell$ l
total 140
drwxrwxr-x  2 julien julien 4096 Dec  4 20:55 .
drwxrwxr-x 17 julien julien 4096 Dec  4 13:04 ..
-rw-rw-r--  1 julien julien  249 Dec  4 13:15 env-environ.c
-rw-rw-r--  1 julien julien  231 Dec  4 13:09 env-main.c
-rwxrwxr-x  1 julien julien 8768 Dec  4 19:52 exec
-rw-rw-r--  1 julien julien  302 Dec  4 19:38 exec.c
-rwxrwxr-x  1 julien julien 8760 Dec  4 20:11 fork
-rw-rw-r--  1 julien julien  438 Dec  4 19:57 fork.c
-rwxrwxr-x  1 julien julien 8656 Dec  4 13:45 mypid
-rw-rw-r--  1 julien julien  179 Dec  4 19:49 pid.c
-rwxrwxr-x  1 julien julien 8656 Dec  4 13:48 ppid
-rw-rw-r--  1 julien julien  180 Dec  4 13:48 ppid.c
-rwxrwxr-x  1 julien julien 8680 Dec  4 13:44 printenv
-rwxrwxr-x  1 julien julien 8760 Dec  4 14:38 prompt
-rwxrwxr-x  1 julien julien 8760 Dec  4 14:38 promptc
-rw-rw-r--  1 julien julien  191 Dec  4 14:17 prompt.c
-rw-rw-r--  1 julien julien  753 Dec  4 20:49 shell.c
-rwxrwxr-x  1 julien julien 8864 Dec  4 20:38 wait
-rw-rw-r--  1 julien julien  441 Dec  4 20:15 wait.c
julien@ubuntu:~/c/shell$ gcc -Wall -Werror -pedantic shell.c -o shell
julien@ubuntu:~/c/shell$ ./shell 
#cisfun$ /bin/ls
env-environ.c  exec    fork    mypid  ppid    printenv  promptc   shell    wait
env-main.c     exec.c  fork.c  pid.c  ppid.c  prompt    prompt.c  shell.c  wait.c
#cisfun$ ./ppid
5451
#cisfun$ ./ppid
5451
#cisfun$ ^C
julien@ubuntu:~/c/shell$ 
```
### The pawelshell
´´´

´´´
