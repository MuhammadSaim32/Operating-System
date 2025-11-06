#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
int count = 0;
mutex mtx;

void task() {

  for (int i = 1; i <= 50000; i++) {
    lock_guard<mutex> lock(
        mtx); // runing with out locks will cause false results

    count += 1;
  }
}

int main() {

  thread t1(task);
  thread t2(task);
  t1.join();
  t2.join();
  cout << count;
  return 0;
}
