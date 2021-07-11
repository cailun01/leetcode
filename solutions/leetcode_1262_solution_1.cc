/* 1262 可被三整除的最大和
给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。

示例 1：
输入：nums = [3,6,5,1,8]
输出：18
解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。

示例 2：
输入：nums = [4]
输出：0
解释：4 不能被 3 整除，所以无法选出数字，返回 0。

示例 3：
输入：nums = [1,2,3,4,4]
输出：12
解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
*/

/*
每个数只有选和不选两种状态，那么根据什么转移呢，因根据当前数模3的余数来进行转移。
状态表示： 
f[i][0]表示到i为止余数为0的最大和
f[i][1]表示到i为止余数为1的最大和
f[i][2]表示到i为止余数为2的最大和
答案：f[n][0]

状态转移：

nums[i−1] mod3 == 0
当前数nums[i−1]模3余0,那么加入当前的数nums[i]不会影响余数的结果
f[i][0] = max(f[i-1][0], f[i-1][0] + nums[i-1])
f[i][1] = max(f[i-1][1], f[i-1][1] + nums[i-1])
f[i][2] = max(f[i-1][2], f[i-1][2] + nums[i-1])

nums[i−1] mod3 == 1
当前数nums[i−1]模3余1,那么加入当前的数nums[i]会将原来余0变成余1，原来余1变成余2，原来余2变成余0，按照定义：
f[i-1][0] + nums[i] ---> f[i][1]
f[i-1][1] + nums[i] ---> f[i][2]
f[i-1][2] + nums[i] ---> f[i][0]
所以得到：
f[i][0] = max(f[i-1][0], f[i-1][2] + nums[i])
f[i][1] = max(f[i-1][1], f[i-1][0] + nums[i])
f[i][2] = max(f[i-1][2], f[i-1][1] + nums[i])

nums[i−1]mod3 == 2
当前数模3余2,分析同上
*/
class Solution {
public:
  int maxSumDivThree(vector<int>& nums) {
    int n = nums.size(), sum = 0;
    vector<vector<int>> f(n + 1, vector<int>(3));
    f[0][0] = 0, f[0][1] = INT_MIN, f[0][2] = INT_MIN;
    for (int i = 1; i <= n; i++) {
      if(nums[i-1] % 3 == 0) {
        f[i][0] = max(f[i - 1][0], f[i - 1][0] + nums[i - 1]);
        f[i][1] = max(f[i - 1][1], f[i - 1][1] + nums[i - 1]);
        f[i][2] = max(f[i - 1][2], f[i - 1][2] + nums[i - 1]);
      } else if (nums[i-1] % 3 == 1) {  
        f[i][0] = max(f[i - 1][0], f[i - 1][2] + nums[i - 1]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] + nums[i - 1]);
        f[i][2] = max(f[i - 1][2], f[i - 1][1] + nums[i - 1]);
      } else {  
        f[i][0] = max(f[i - 1][0], f[i - 1][1] + nums[i - 1]);
        f[i][1] = max(f[i - 1][1], f[i - 1][2] + nums[i - 1]);
        f[i][2] = max(f[i - 1][2], f[i - 1][0] + nums[i - 1]);
      }
    }
    return f[n][0];
  }
};