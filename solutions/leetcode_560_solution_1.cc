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