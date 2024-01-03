# C - Simple Shell
**Write a simple UNIX command interpreter**
### Resources
* [Unix shell](https://en.wikipedia.org/wiki/Unix_shellhttps://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Ken Thomsopn](https://en.wikipedia.org/wiki/Ken_Thompson)
## Learning Objectives
* Who designed and implemented the original Unix operating system
	* In 1969 a team led by computer scientists Ken Thompson and Dennis Ritchie created the first version of UNIX on a PDP-7 minicomputer, which was chosen mainly because of Thompson's familiarity with the system from his hobby work on it.<br />

* Who wrote the first version of the UNIX shell
	* The first Unix shell was the Thompson shell, sh, written by Ken Thompson at Bell Labs and distributed with Versions 1 through 6 of Unix, from 1971 to 1975<br />

* Who invented the B programming language (the direct predecessor to the C programming language)
	* Ken thomspson had worked at Bell Labs and also invented the B programming language.<br />

* Who is Ken Thompson
	*  An american pioneer of computer science. is a great contributor of the original Unix operating system.<br />

* How does a shell work
	* When you type a command at the prompt and press the Enter key, the shell evaluates the command and attemps to carry it out.<br />


* What is a pid and a ppid
	* The process identifier is a number used by most operating system kernels, such as those of Unix. To uniquely identify an active process.<br />

* How to manipulate the environment of the current proces
	* **ps**: The `ps` command is used to list all the currently running processes in the system and information related to them, this information consists of the process name, user, memory consumption, CPU consumption, process ID.
	* **sleep**: The sleep command is used in Linux to delay a running program by a certain amount of time. The amount of time to be delayed can be specified in seconds, minutes, hours, and even days.
	* **jobs**: The jobs command in Linux is used to list the status of all the jobs currently running in the terminal along with their job number. This lists only those processes which started running in this session.
	* **bg**: The bg command is used to push a suspended process into the background where it can continue to run.
	* **fg**: Similar to `bg`, the `fg` command is used to bring back a suspended process in the background to the foreground.
	* **kill**: The `kill` command is used to kill or stop a currently running process. The kill command can be used both with the job number and the process ID.
	* [Summary](https://i.imgur.com/wrxahsx.jpeg)
* What is the difference between a function and a system call
	* A system call has more privilege than a normal subroutine. A system call runs with kernel-mode privilege in the kernel protection domain. System call code and data are located in global kernel memory.<br />

* How to create processes
	* **In Linux, there are 2 ways of creating a new process, let us look at them:**

	* system() The first method of creating a process in Linux is by using the function system(). ...
	* fork() / exec() The second method of creating a process in Linux is by using either the fork() function or the exec() function.
* What are the three prototypes of `main`
	* main have only two protoypes: `int main (void);` `int main (int argc, char ** argv);` <br />

* How does the shell use the `PATH` to find the programs.
	* The shell searches each directory in the path. If a command is not found, long searches can slow down system performance. The search path is read from left to right, so you should put directories for commonly used commands at the beginning of the path. Make sure directories are not duplicated in the path.<br />

* How to execute another program with the execve system call.
	* The execve system call replaces the current process with a new program. The syntax of execve is: 
	* `int execve(const char *path, char *const argv[], char *const evnp[]`<br />

* How to suspend the execution of a process until one of its children terminates
	* In order to wait for a child process to terminate, a parent process will just execute a `wait()` system call. This call will suspend the parent process until any of its child processes terminates, at which time the `wait()` call returns and the parent process can continue.<br />

* What is `EOF` / "end-of-file"?
	* is a condition where no more data can be read from a data source, idicating the end of the file.<br />

* Why we used system call only when its needed 
	*  System calls are expensive due to context switching, kernel mode execution, data copying, and synchronization overhead.<br /> :wqrTo reduce the expense of system calls, it is recommended to use them only when necessary. Frequent or unnecessary system calls can lead to slower execution, reduced efficiency, and inefficient resource utilization.<br />


