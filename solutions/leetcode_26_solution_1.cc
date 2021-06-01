/* 26 删除排序数组中的重复项
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) { 
      return 0;
    }
    int length = nums.size();
    int fast = 0, slow = 0;
    while (fast < length) {
      if (nums[fast] != nums[slow]) {
        slow++;
        nums[slow] = nums[fast];
      }
      fast++;
    }
    return slow + 1;
  }
};