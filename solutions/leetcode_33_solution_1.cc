#include "headers.h"
// 二分查找
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int length = nums.size();
    // 如果nums的长度为1
    if(length == 1) { 
      return nums[0] == target ? 0 : -1; 
    }
    int left = 0, right = length - 1;
    while(left <= right) {
      int mid = (right + left) / 2;
      if(nums[mid] == target) { 
        return mid; 
      }
      // 如果在左边的单增序列上
      if(nums[0] <= nums[mid]) {
        if(nums[0] <= target && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {// 如果在右边的单增序列上
        if(nums[mid] < target && target <= nums[length - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
      }
    }
    return -1;
  }
};
