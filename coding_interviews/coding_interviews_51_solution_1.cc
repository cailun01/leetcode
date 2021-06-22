/* 剑指 Offer 51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。

示例 1:
输入: [7,5,6,4]
输出: 5
*/

/*
https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/solution/jian-zhi-offer-51-shu-zu-zhong-de-ni-xu-pvn2h/
*/

class Solution {
public:
  int reversePairs(vector<int>& nums) {
    vector<int> tmp(nums.size());
    return mergeSort(0, nums.size() - 1, nums, tmp);
  }
private:
  int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp) {
    // 终止条件
    if (l >= r) return 0;
    // 递归划分
    int m = (l + r) / 2;
    int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
    // 合并阶段，设置双指针 i , j 分别指向左 / 右子数组的首元素
    int i = l, j = m + 1;
    for (int k = l; k <= r; k++) {
      // 把数组 nums 闭区间 [l,r] 内的元素暂存至辅助数组tmp ；
      tmp[k] = nums[k];
    }
    for (int k = l; k <= r; k++) {
      if (i == m + 1) {
        // 代表左子数组已合并完，因此添加右子数组当前元素tmp[j] ，并执行j=j+1 ；
        nums[k] = tmp[j++];
      } else if (j == r + 1 || tmp[i] <= tmp[j]) {
        // 添加左子数组当前元素tmp[i] ，并执行i=i+1；
        nums[k] = tmp[i++];
      } else { // tmp[i] > tmp[j]
        // 添加右子数组当前元素tmp[j] ，并执行j=j+1 ；此时构成m-i+1 个「逆序对」
        nums[k] = tmp[j++];
        // 因为i~m之间是有序的，所以如果tmp[i]>tmp[j]，那么tmp[i]之后的元素一定
        // 大于tmp[j]
        res += m - i + 1; // 统计逆序对
      }
    }
    return res;
  }
};
