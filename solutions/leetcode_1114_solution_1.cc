/* 1114 按序打印
我们提供了一个类：

public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
三个不同的线程 A、B、C 将会共用一个 Foo 实例。

一个将会调用 first() 方法
一个将会调用 second() 方法
还有一个将会调用 third() 方法
请设计修改程序，以确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行。

示例 1:

输入: [1,2,3]
输出: "firstsecondthird"
解释: 
有三个线程会被异步启动。
输入 [1,2,3] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 second() 方法，线程 C 将会调用 third() 方法。
正确的输出是 "firstsecondthird"。
示例 2:

输入: [1,3,2]
输出: "firstsecondthird"
解释: 
输入 [1,3,2] 表示线程 A 将会调用 first() 方法，线程 B 将会调用 third() 方法，线程 C 将会调用 second() 方法。
正确的输出是 "firstsecondthird"。
 

提示：

尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。
你看到的输入格式主要是为了确保测试的全面性
*/

/*
用一个互斥量、一个条件变量、和一个计数器count。
second和third只有在计数器到达指定值时才会执行print。
first执行printFirst()后，修改count使cv.wait中的条件为True，用notify_all通知。
second执行printSecond()后，修改count使cv.wait中的条件为True，用notify_one通知。
*/

class Foo {
private:
  int flag;
  mutex mtx;
  condition_variable cv;
public:
  Foo() : flag(1) {
      
  }

  void first(function<void()> printFirst) {
    unique_lock<mutex> lock(mtx);
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    flag = 2;
    cv.notify_all();
  }

  void second(function<void()> printSecond) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [this](){ return flag == 2; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    flag = 3;
    cv.notify_one();
  }

  void third(function<void()> printThird) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [this](){ return flag == 3; });
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
