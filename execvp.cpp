#include<iostream>        // For cout
#include <unistd.h>       // For execvp()
using namespace std;

int main() {

    // Create argument array for execvp
    // First: program name "pwd", then: NULL terminator
    char *arr[] = {
        const_cast<char *>("pwd"),  // Cast string literal to char*
        nullptr                     // Null terminator to mark end of argument list
    };

    // Replace current process with "pwd"
    // If execvp succeeds, this line does NOT return
    execvp("pwd", arr);

    // Only printed if execvp fails (e.g., "pwd" not found)
    cout << "ok";

    return 0;
}
