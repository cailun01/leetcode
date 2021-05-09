/*
二分查找解法，这个解法的时间复杂度会将为 O(NlogN)。

最长递增子序列和一种叫做 patience game 的纸牌游戏有关，甚至有一种排序方法就叫做 patience sorting（耐心排序）。

首先，给你一排扑克牌，我们像遍历数组那样从左到右一张一张处理这些扑克牌，最终要把这些牌分成若干堆。

处理这些扑克牌要遵循以下规则：

只能把点数小的牌压到点数比它大的牌上。如果当前牌点数较大没有可以放置的堆，
则新建一个堆，把这张牌放进去。如果当前牌有多个堆可供选择，则选择最左边的堆放置。

为什么遇到多个可选择堆的时候要放到最左边的堆上呢？因为这样可以保证牌堆顶的牌有序（2, 4, 7, 8, Q），证明略。

按照上述规则执行，可以算出最长递增子序列，牌的堆数就是我们想求的最长递增子序列的长度，证明略。

我们只要把处理扑克牌的过程编程写出来即可。每次处理一张扑克牌不是要找一个合适的牌堆顶来放吗，
牌堆顶的牌不是有序吗，这就能用到二分查找了：用二分查找来搜索当前牌应放置的位置。

https://mp.weixin.qq.com/s?src=11&timestamp=1620564472&ver=3058&signature=7N7ByeOqTZeZ7NDd2It3Pe9x6iQEldkfSmYWc1VitGq9eBQrjk65xEQpy7iuJTgA6tkPuZTx1Ni1KVDJr2axFq6yiwYTOvil4bIbACtDJQk3LvMqNSU3E9Qmvvx28*DI&new=1
*/

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> top(nums.size());
    int piles = 0;
    for (int i = 0; i < nums.size(); i++) {
      int poker = nums[i];

      int left = 0, right = piles;
      while (left < right) {
        int mid = (left + right) / 2;
        if (top[mid] > poker) {
          right = mid;
        } else if (top[mid] < poker) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
      
      if (left == piles) {
        piles++;
      }
      top[left] = poker;
    }
    return piles;
  }
  
};