/*
我们提供一个类：

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
两个不同的线程将会共用一个 FooBar 实例。其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。

请设计修改程序，以确保 "foobar" 被输出 n 次。

示例 1:
输入: n = 1
输出: "foobar"
解释: 这里有两个线程被异步启动。其中一个调用 foo() 方法, 另一个调用 bar() 方法，"foobar" 将被输出一次。

示例 2:
输入: n = 2
输出: "foobarfoobar"
解释: "foobar" 将被输出两次。
*/
/*
std::this_thread::yield() 是让当前线程让渡出自己的CPU时间片(给其他线程使用)
*/
class FooBar {
private:
    int n;
    atomic<bool> foo_done = false;
public:
    FooBar(int n) : n(n) {}

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            while (foo_done) {
                this_thread::yield();
            }
            printFoo();
            foo_done = true;
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            while (!foo_done) {
                this_thread::yield();
            }
            printBar();
            foo_done = false;
        }
    }
};
