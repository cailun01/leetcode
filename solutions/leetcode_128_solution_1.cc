/* 128 最长连续序列
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

进阶：你可以设计并实现时间复杂度为O(n)的解决方案吗？

示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
*/

/* 
首先通过set将nums去重并且hash。然后我们遍历nums中的元素x，先判断x-1是不是在nums中（也就是先确定连续数组的最小值），
如果不在的话，我们接着判断x+1是不是在nums中，接着判断x+2是不是在nums中，类推下去。如果x-1在nums中，则以x为开头的序列
一定不是最长连续序列。这样我们就可以找到最长的连续数组。

外层循环需要O(n)的时间复杂度，只有当一个数是连续序列的第一个数的情况下才会进入内层循环，
然后在内层循环中匹配连续序列中的数，因此数组中的每个数只会进入内层循环一次。
根据上述分析可知，总时间复杂度为 O(n)，符合题目要求。
*/
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> num_set;
    for (const int& num : nums) {
      num_set.insert(num);
    }
    // 最长序列的长度
    int longestStreak = 0;

    for (const int& num : num_set) {
      // num - 1如果在set中，则以num开头的子序列一定不是最长连续序列
      if (num_set.find(num - 1) == num_set.end()) {
        int currentNum = num;
        int currentStreak = 1;
        // num + 1在set中，更新最长序列的长度
        while (num_set.find(currentNum + 1) != num_set.end()) {
          currentNum += 1;
          currentStreak += 1;
        }
        longestStreak = max(longestStreak, currentStreak);
      }
    }
    return longestStreak;           
  }
};
