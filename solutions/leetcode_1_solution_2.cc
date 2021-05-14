#include "headers.h"
// 用Hash表，时间复杂度为O(n)，空间复杂度为O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hash的key是数组中元素的值，value是该元素在数组的下标
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            hash[nums[i]] = i;
        }
        vector<int> re;
        for (int j = 0; j < nums.size(); ++j) {
            int complement = target - nums[j];
            auto it = hash.find(complement);
            if (it != hash.end()) {
                // 如果找到了complement而且它的下标不是当前元素的下标j
                // 则complement和nums[j]是两个不同的数
                if (hash[complement] != j) {
                    re.push_back(j);
                    re.push_back(hash[complement]);
                    return re;
                }   
            }
        }
        return re;
    }
};