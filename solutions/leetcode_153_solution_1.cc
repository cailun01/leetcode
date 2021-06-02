#include "headers.h"
// 时间复杂度O(n)，非最优解
class Solution {
public:
  int findMin(vector<int>& nums) {
    if (nums.size() == 1) return nums.at(0);
    for (int i = 1; i < nums.size(); ++i) {
      if (nums.at(i - 1) > nums.at(i)) {
        return nums.at(i);
      }
    }
    return nums.at(0);
  }
};