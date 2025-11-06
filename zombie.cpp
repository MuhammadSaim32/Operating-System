#include <iostream>
#include <sys/types.h>
#include <unistd.h> // for fork(), sleep(), getpid(), getppid()
using namespace std;

int main() {
  pid_t pid = fork();

  if (pid > 0) {
    cout << "Parent PID: " << getpid() << endl;
    cout << "Child PID: " << pid << endl;
    cout << "Parent sleeping for 10 seconds..." << endl;

    // Parent sleeps to keep running while child dies
    sleep(10);
    cout << "Parent exiting now..." << endl;
  } else if (pid == 0) {
    //  Child process
    cout << "Child PID: " << getpid() << " exiting immediately..." << endl;
    _exit(0); // child exits quickly
  } else {
    cerr << "Fork failed!" << endl;
  }

  return 0;
}
