#include "headers.h"
// 双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 2) return {};
        sort(nums.begin(),nums.end());//排序
        vector<vector<int>> res;
        for(int k = 0; k < nums.size() - 2; ++k){
            if(k > 0 && nums[k] == nums[k-1])
                continue;
            if(nums[k] > 0)
                break; 
            int l = k + 1;
            int r = nums.size() - 1;
            while (l < r){ //循环
                if(nums[k] + nums[l] + nums[r] == 0){
                    res.push_back({nums[k],nums[l],nums[r]}); //存入二维数组
                    l++;
                    r--;
                    while(nums[l] == nums[l-1] && l < r)
                        ++l;
                    while(nums[r] == nums[r+1] && l < r)
                        r--;
                }
                else if(nums[k] + nums[l] + nums[r] > 0){
                    r--;
                } else { // (nums[k] + nums[l] + nums[r] < 0)
                    l++;
                }
            }
        }
        return res;
    }
};