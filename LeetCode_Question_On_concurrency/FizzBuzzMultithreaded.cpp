class FizzBuzz {
private:
  int n;
  condition_variable cv;
  mutex m;
  int i;
  int s;

public:
  FizzBuzz(int val) {
    s = val;
    i = 1;
  }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    while (i <= s) {
      unique_lock<mutex> lock(m);
      while ((i % 3 != 0 || i % 5 == 0) && i <= s) {
        cv.wait(lock);
      }
      if (i > s) {
        break;
      }

      printFizz();
      i += 1;

      cv.notify_all();
    }
    cv.notify_all();
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {

    while (i <= s) {
      unique_lock<mutex> lock(m);
      while ((i % 5 != 0 || i % 3 == 0) && i <= s) {
        cv.wait(lock);
      }
      if (i > s) {
        break;
      }

      printBuzz();
      i += 1;

      cv.notify_all();
    }
    cv.notify_all();
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    while (i <= s) {
      unique_lock<mutex> lock(m);
      while ((i % 3 != 0 || i % 5 != 0) && i <= s) {
        cv.wait(lock);
      }

      if (i > s) {
        break;
      }

      printFizzBuzz();
      i += 1;

      cv.notify_all();
    }
    cv.notify_all();
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {

    while (i <= s) {
      unique_lock<mutex> lock(m);
      while ((i % 3 == 0 || i % 5 == 0) && i <= s) {
        cv.wait(lock);
      }
      if (i > s) {
        break;
      }

      printNumber(i);
      i += 1;

      cv.notify_all();
    }
    cv.notify_all();
  }
};
