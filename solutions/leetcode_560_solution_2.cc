/* 560 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
*/

/*
用优化后的前缀和求解，时间复杂度O(n)

前面的解法有嵌套的 for 循环：
for (int i = 1; i <= n; i++)
    for (int j = 0; j < i; j++)
        if (sum[i] - sum[j] == k)
            ans++;
第二层 for 循环在干嘛呢？翻译一下就是，在计算，有几个j能够使得sum[i]和sum[j]的差为 k。
毎找到一个这样的j，就把结果加一。

我们可以把 if 语句里的条件判断移项，这样写：
if (sum[j] == sum[i] - k)
    ans++;
优化的思路是：我直接记录下有几个sum[j]和sum[i]-k相等，直接更新结果，就避免了内层的 for 循环。
我们可以用哈希表，在记录前缀和的同时记录该前缀和出现的次数。
*/
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int size = nums.size();
    // key: 前缀和，value: 该前缀和出现的次数
    unordered_map<int, int> pre_sum; 
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
