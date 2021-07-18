#include "headers.h"
/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
*/

// 堆排序
class Solution {
private:
  priority_queue<int, vector<int>, greater<int>> pq; // 小顶堆
public:
  int findKthLargest(vector<int>& nums, int k) {
    for (int& i : nums) {
      // 每个元素都要过一遍二叉堆
      pq.push(i);
      if (pq.size() > k) {
        // 堆中元素多于 k 个时，删除堆顶元素
        // 被弹出的元素都是较小的
        pq.pop();
      }
    }
    // pq 中剩下的是 nums 中 k 个最大元素，
    // 堆顶是最小的那个，即第 k 个最大元素
    return pq.top();
  }
};