/* 27 移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/

/*
从fast=0, slow=0开始，如果nums[fast]一直不等于val，那么每一轮while循环，fast与slow都会右移一步。
直到fast遇到nums[fast]等于val的情况，此时fast开始和slow不同步，而slow刚好也指向val。
*/
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int fast = 0, slow = 0;
    while (fast < nums.size()) {
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        slow++;
      }
      fast++;
    }
    return slow;
  }
};