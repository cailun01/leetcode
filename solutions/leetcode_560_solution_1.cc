/* 560 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
*/

/*
用前缀和求解。时间复杂度O(n^2), 空间复杂度O(n)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        // 构造前缀和
        vector<int> pre_sum(size + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre_sum[i + 1] = nums[i] + pre_sum[i];
        }

        int ans = 0;
        // 穷举所有子数组
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // sum of nums[j..i-1]
                if (pre_sum[i] - pre_sum[j] == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};