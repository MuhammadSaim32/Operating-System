#include <iostream>
#include <csignal>
using namespace std;

void handler(int sig) {
    cout << "Caught signal: " << sig << endl;
    // You can clean up here (like closing files, saving logs, etc.)
    
}

int main() {
	int i=0;
    signal(SIGINT, handler);  // Handle Ctrl+C
    while (true) {
        cout<<++i<<" "<< "Running..." << endl;
        sleep(1);
    }
    return 0;
}
