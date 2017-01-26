/*
SIGBUS - Bus error
SIGSEGV - Segmentation Violation
SIGFPE - Floating Point Exception
SIGTERM - Requests process to terminate, may or may not terminate
SIGKILL - Kills the process immediately. Cannot be handled by a program
SIGUSR1, SIGUSR2 - User defined signals
SIGHUP - Wake up an idling program
SIGINT - Is sent to a process when the user attempts to end it by typing Ctrl+C
SIGABRT - By calling abort function. Terminates and produces a core file.
SIGCHLD - When a child process terminates, linux send the parent process.


Signal Disposition - What happens to the process if the program specifies certain behavior when a signal is received.
Signal Handler - For handling signals.
When a signal handler is specified, when such a signal is received, the program pauses, executes signal handler and when the signal handler returns, the program resumes.

"sigaction" function can be used to set a signal disposition.
3 args:
1. signal number
2. sigaction structure - contains desired disposition for that signal number
3. sigaction structure - contains previous disposition
has a member sa_handler which takes:
SIG_DFL - default disposition for the signal
SIG_IGN - signal should be ignored
A pointer to a signal-handler function. The function should take one parameter, the signal number and return void

Dont use global variables for handling signals. Use atomics.

SIGTERM is sent by the kill command

*/

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;

void handler(int signal_number)
{
  ++sigusr1_count;
}

int main()
{
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = &handler;
  sigaction(SIGTERM, &sa, NULL);
  while(1){}
  printf("SIGUSR1 was raised %d times\n",sigusr1_count);
  return 0;
}
