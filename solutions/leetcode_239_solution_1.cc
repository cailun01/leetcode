/* 239 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

示例 2：
输入：nums = [1], k = 1
输出：[1]

示例 3：
输入：nums = [1,-1], k = 1
输出：[1,-1]

示例 4：
输入：nums = [9,11], k = 2
输出：[11]

示例 5：
输入：nums = [4,-2], k = 2
输出：[4]
*/

// 单调队列，队首元素是最大值，依次单调递减
class MonotonicQueue {
private:
  // // 双链表，支持头部和尾部增删元素
  list<int> q;
public:
  int max() {
    // 队头的元素肯定是最大的
    return q.front();
  }

  void push(int n) {
    // 将前面小于n的元素都删除
    while (!q.empty() && q.back() < n) {
      q.pop_back();
    }
    q.push_back(n);
  }

  // 队头元素如果是 n，删除它
  // 如果n不是最大值(不在对头)，那么队列里是没有的
  // 因为在push时就被pop_back了
  void pop(int n) {
    if (n == q.front()) {
      q.pop_front();
    }
  }
};

class Solution {
private:
  MonotonicQueue window;
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
      if (i < k - 1) {
        //先把窗口的前 k - 1 填满
        window.push(nums[i]);
      } else {
        window.push(nums[i]);
        result.push_back(window.max());
        window.pop(nums[i - k + 1]);
      }
    }
    return result;
  }
};