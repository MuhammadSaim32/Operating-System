class ZeroEvenOdd {
private:
  int n;
  int i;
  condition_variable cv;
  mutex m;
  int turn;

public:
  ZeroEvenOdd(int n) {
    this->n = n;
    turn = 0;
    i = 1;
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {

    while (i <= n) {
      if (i > n)
        break;
      unique_lock<mutex> lock(m);
      while (turn == 1 && i <= n) {
        cv.wait(lock);
      }
      if (i > n) {
        break;
      }
      printNumber(0);
      turn = 1;
      cv.notify_all();
    }
    cv.notify_all();
  }

  void even(function<void(int)> printNumber) {

    while (i <= n) {
      if (i > n)
        break;

      unique_lock<mutex> lock(m);
      while ((turn != 1 || i % 2 != 0) && i <= n) {
        cv.wait(lock);
      }
      if (i > n) {
        break;
      }
      printNumber(i);
      i++;
      turn = 0;
      cv.notify_all();
    }
    cv.notify_all();
  }

  void odd(function<void(int)> printNumber) {
    while (i <= n) {
      if (i > n)
        break;

      unique_lock<mutex> lock(m);
      while ((turn == 0 || i % 2 == 0) && i <= n) {
        cv.wait(lock);
      }
      if (i > n) {
        break;
      }

      printNumber(i);
      i++;
      turn = 0;
      cv.notify_all();
    }
    cv.notify_all();
  }
};
