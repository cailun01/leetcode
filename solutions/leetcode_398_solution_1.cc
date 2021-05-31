/* 398 随机数索引
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

示例:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
solution.pick(3);

// pick(1) 应该返回 0。因为只有nums[0]等于1。
solution.pick(1);
*/

/*
水塘抽样，参见知乎 https://zhuanlan.zhihu.com/p/29178293

核心思路
对于需要随机的数字做计数i，i=1，则概率就是1
i=2，概率就是 1/2
i=3, 概率就是 1/3
总结就是按照当前计数i，只取1/i的概率选择该结果，那么最后对于所有1-都是是平均1/i的概率
*/
class Solution {
private:
  vector<int> nums;
  int n;
public:
  Solution(vector<int>& nums) : nums(nums) {
    n = nums.size();
  }
  
  int pick(int target) {
    // 计数器，默认是1
    int cnt = 1;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int num = nums[i];
      if (num == target) {
        // 发现预期的数字，则开始一次随机数，如果正好是1/i概率则更新结果
        if ((rand() % cnt + 1) == 1) {
          res = i;
        }
        ++cnt;
      }
    }

    return res;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */