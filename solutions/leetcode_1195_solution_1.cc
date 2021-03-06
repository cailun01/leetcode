/* 1195. 交替打印字符串
编写一个可以从 1 到 n 输出代表这个数字的字符串的程序，但是：

如果这个数字可以被 3 整除，输出 "fizz"。
如果这个数字可以被 5 整除，输出 "buzz"。
如果这个数字可以同时被 3 和 5 整除，输出 "fizzbuzz"。
例如，当 n = 15，输出： 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz。

假设有这么一个类：

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
请你实现一个有四个线程的多线程版  FizzBuzz， 同一个 FizzBuzz 实例会被如下四个线程使用：

线程A将调用 fizz() 来判断是否能被 3 整除，如果可以，则输出 fizz。
线程B将调用 buzz() 来判断是否能被 5 整除，如果可以，则输出 buzz。
线程C将调用 fizzbuzz() 来判断是否同时能被 3 和 5 整除，如果可以，则输出 fizzbuzz。
线程D将调用 number() 来实现输出既不能被 3 整除也不能被 5 整除的数字。
*/

/*
std::this_thread::yield的作用：
比如说你的线程需要等待某个操作完成，如果你直接用一个循环不断判断这个操作是否完成就会使得这个线程占满CPU时间，
这会造成资源浪费。这时候你可以判断一次操作是否完成，如果没有完成就调用yield交出时间片，
过一会儿再来判断是否完成，这样这个线程占用CPU时间会大大减少。
*/

class FizzBuzz {
private:
  int n;
  int i; // 全局索引，从1开始
public:
  FizzBuzz(int n) {
    this->n = n;
    this->i = 1;
  }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    while(true) {
      if (i == n + 1) {
        break;
      }
      if (i % 3 == 0 && i % 5 != 0) {
        printFizz();
        i++;
      } else {
        this_thread::yield();
      }
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    while(true) {
      if (i == n + 1) {
        break;
      }
      if (i % 5 == 0 && i % 3 != 0) {
        // 能被5整除、不能被3整除
        printBuzz();
        i++;
      } else {
        this_thread::yield();
      }       
    }
  }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
    while(true) {
      if (i == n + 1) {
        break;
      }
      if (i % 5 == 0 && i % 3 == 0) {
        // 既能被5整除、也能被3整除
        printFizzBuzz();
        i++;
      } else {
        this_thread::yield();
      }
    }     
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {      
    while(true) {
      if (i == n + 1) {
        break;
      }
      if (i % 5 != 0 && i % 3 != 0) {
        // 普通索引，不能被5整除也不能被3整除。
        printNumber(i);
        i++;
      } else {
        this_thread::yield();
      }
    }     
  }
};
