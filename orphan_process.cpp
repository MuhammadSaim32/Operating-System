#include <iostream>
#include <sys/types.h>
#include <unistd.h> // for fork(), sleep(), getpid(), getppid()

using namespace std;

int main() {
  pid_t pid = fork(); // create a child process

  if (pid > 0) {
    cout << "Parent process PID: " << getpid() << endl;
    cout << "Parent exiting now..." << endl;
    _exit(0); // parent exits immediately
  } else if (pid == 0) {
    //  Child process
    cout << "Child process PID: " << getpid() << endl;
    cout << "Child's parent PID before sleep: " << getppid() << endl;

    sleep(5); // wait so parent can exit

    cout << "Child's parent PID after parent exited: " << getppid() << endl;
    cout << "Child still running (orphan adopted by init/systemd)." << endl;
  } else {
    cerr << "Fork failed!" << endl;
  }

  return 0;
}
