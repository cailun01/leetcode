/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
*/

/*
用优化后的前缀和求解，时间复杂度O(n)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> pre_sum; // key: 前缀和，value: 该前缀和出现的次数
        pre_sum[0] = 1;

        int ans = 0, sum0_i = 0;
        for (int i = 0; i < size; ++i) {
            sum0_i += nums[i];
            int sum0_j = sum0_i - k;
            if (pre_sum.find(sum0_j) != pre_sum.end()) {
                ans += pre_sum[sum0_j];
            }
            pre_sum[sum0_i]++;
        }
        return ans;
    }
};