#include "headers.h"
/* 15. 三数之和

给你一个包含n个整数的数组 nums，判断 nums 中是否存在三个元素 a,b,c ，
使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/

// 双指针
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 2) return {};
    //排序
    sort(nums.begin(),nums.end());
    vector<vector<int>> res;
    for (int k = 0; k < nums.size() - 2; ++k) {
      if (k > 0 && nums[k] == nums[k-1]) {
        // 不考虑重复数字
        continue;
      }
      if(nums[k] > 0) {
        // 如果nums[k]>0,则nums[l],nums[r]一定大于0
        break; 
      }
      int l = k + 1;
      int r = nums.size() - 1;
      while (l < r) { //循环
        if (nums[k] + nums[l] + nums[r] == 0) {
          res.push_back({nums[k], nums[l], nums[r]}); //存入二维数组
          l++;
          r--;
          while(nums[l] == nums[l-1] && l < r) {
            // 不考虑重复数字
            l++;
          }
          while(nums[r] == nums[r+1] && l < r) {
            // 不考虑重复数字
            r--;
          }
        } else if (nums[k] + nums[l] + nums[r] > 0){
          r--;
        } else { // (nums[k] + nums[l] + nums[r] < 0)
          l++;
        }
      }
    }
    return res;
  }
};
