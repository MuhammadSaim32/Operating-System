#include <iostream>    // For cout
#include <unistd.h>    // For fork()
#include <sys/wait.h>  // For wait()
using namespace std;

int main() {
    int pid = fork();  // Create a child process. Returns:
                       // 0 in child, >0 in parent (child's PID), <0 on error

    if (pid == 0) {
        // This block runs only in the child process
        cout << "Child process\n";
    } 
    else if (pid < 0) {
        // If fork fails, this block runs
        cout << "Fork failed\n";
    } 
    else {
        // This block runs in the parent process
        cout << "You are the parent process, and this is the child's PID = " << pid << endl;

        wait(NULL);  // Parent waits for the child to finish


        cout << "Child ends\n";  // After child finishes
    }

    cout << "Done\n";  // Runs in both parent and child
    return 0;
}
