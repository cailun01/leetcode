
/*
https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia
先看一个例子：
2,3,6,5,4,1
有一部分递增：2,3；另一部分递减：6,5,4,1

1. 从右至左遍历，找到第一个元素，该元素不符合从右至左递增的顺序，本例中是数字3。
2. 
2.1 如果找不到符合第一步条件的元素，即数组从右至左是严格递增的：6,5,4,3,2,1。因此是最后一个全排列。只需要翻转整个数组即可。
2.2 如果我们找到了该元素，那么下一步，我们再次从右往左遍历，找到第一个大于3的元素，本例中是4。
    接着我们交换3和4得到：2,4,6,5,3,1。最后，翻转4右侧的子数组得到2,4,1,3,5,6，即下一个全排列。
*/
class Solution {
public:
    void reverse(vector<int>& nums, int s, int e) {
      while (s < e) {
        swap(nums[s], nums[e]);
        s++;
        e--;
      }
    }

    void nextPermutation(vector<int>& nums) {
      int n = nums.size();
      int pointer = -1;
      int pointer_value = 0;
      for (int i = n - 2; i >=0; i--) {
        if (nums[i] < nums[i + 1]) {
          pointer = i;
          pointer_value = nums[i];
          break;
        }
      }
      if (pointer == -1) {
        reverse(nums, 0, n - 1);
        return;
      }

      for (int i = n - 1; i >= 0; i--) {
        if (nums[i] > pointer_value) {
          swap(nums[pointer], nums[i]);
          break;
        }
      }
      reverse(nums, pointer + 1, n - 1);
    }
};
