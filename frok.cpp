#include <iostream>
#include <unistd.h>   // for fork()

using namespace std;

int main() {
    int pid = fork();
    

    if (pid == 0) {
        // Child process
        cout << "Child process\n";
    } else if (pid < 0) {
        // Fork failed
        cerr << "Fork failed\n";
    } else {
        // Parent process
        cout << "Your are Parent process, And This is child's PID = " << pid << endl;
    }

    return 0;
}
