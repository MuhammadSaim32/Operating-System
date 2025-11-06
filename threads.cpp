#include <iostream>
#include <thread>
using namespace std;

void taskA() {
  for (int i = 0; i <= 5; i++) {
    cout << "taskA : " << i << endl;
  }
}

void taskB() {
  for (int i = 0; i <= 5; i++) {
    cout << "taskB : " << i << endl;
  }
}

int main() {

  thread t1(taskA);
  thread t2(taskB);
  t1.join();
  t2.join();

  return 0;
}
