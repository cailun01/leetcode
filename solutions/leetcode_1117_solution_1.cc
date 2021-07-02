/* 1117. H2O生成
现在有两种线程，氧 oxygen 和氢 hydrogen，你的目标是组织这两种线程来产生水分子。

存在一个屏障（barrier）使得每个线程必须等候直到一个完整水分子能够被产生出来。

氢和氧线程会被分别给予 releaseHydrogen 和 releaseOxygen 方法来允许它们突破屏障。

这些线程应该三三成组突破屏障并能立即组合产生一个水分子。

你必须保证产生一个水分子所需线程的结合必须发生在下一个水分子产生之前。

换句话说:

如果一个氧线程到达屏障时没有氢线程到达，它必须等候直到两个氢线程到达。
如果一个氢线程到达屏障时没有其它线程到达，它必须等候直到一个氧线程和另一个氢线程到达。
书写满足这些限制条件的氢、氧线程同步代码。

示例 1:
输入: "HOH"
输出: "HHO"
解释: "HOH" 和 "OHH" 依然都是有效解。

示例 2:
输入: "OOHHHH"
输出: "HHOHHO"
解释: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" 和 "OHHOHH" 依然都是有效解。

*/

/*
两个变量count_o和count_h分别对氧气和氢气计数。
hydrogen函数中的条件变量，当count_h < 2时，可以调用releaseHydrogen，
然后count_h++。如果count_o + count_h == 3。count_o和count_h清零。

oxygen函数中的条件变量，当count_o < 1时，可以调用releaseOxygen，
然后count_o++。如果count_o + count_h == 3。count_o和count_h清零。
*/

class H2O {
public:
  // 氧气的计数
  int count_o;
  // 氢气的计数
  int count_h;
  mutex m;
  condition_variable cv;

  H2O() {
    count_o = 0;
    count_h = 0;
  }

  void hydrogen(function<void()> releaseHydrogen) {
    unique_lock<mutex> l(m);
    cv.wait(l, [this](){
        // 氢气最大是2
        return this->count_h < 2;
    });
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    ++count_h;
    // 已经构成 H2O ，重置计数器
    if (count_h + count_o == 3) {
        count_h = 0;
        count_o = 0;
    }
    cv.notify_one();
  }

  void oxygen(function<void()> releaseOxygen) {
    unique_lock<mutex> l(m);
    cv.wait(l, [this](){
      // 氧气最大是1
      return this->count_o < 1;
    });
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    ++count_o;
    // 已经构成 H2O ，重置计数器
    if (count_h + count_o == 3) {
        count_h = 0;
        count_o = 0;
    }
    cv.notify_one();
  }
};
