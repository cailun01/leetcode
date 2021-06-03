/* 283 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
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

  void moveZeroes(vector<int>& nums) {
    int p = removeElement(nums, 0);
    for (; p < nums.size(); ++p) {
      nums[p] = 0;
    }
  }
};