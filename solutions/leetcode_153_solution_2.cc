#include "headers.h"
// 二分查找

class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      if (nums[left] <= nums[right]) { 
        return nums[left]; 
      }
      int mid = (left + right) / 2;
      if (nums[left] <= nums[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};