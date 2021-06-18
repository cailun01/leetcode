/* 496. 下一个更大元素1
给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。

请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。
如果不存在，对应位置输出 -1 。

示例 1:
输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。

示例 2:
输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
 
提示：

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
nums1和nums2中所有整数 互不相同
nums1 中的所有整数同样出现在 nums2 中
 

进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？
*/

/* 单调栈。for循环扫描nums2时，从右至左扫描，保证栈中元素都是nums2[i]右侧的元素，
离nums2[i]越近，在栈里的位置越靠上。
*/ 
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // key: element in nums2, 
    // value: element's next greater number
    unordered_map<int, int> next_greater; 
    // 单调栈
    stack<int> s;
    for (int i = nums2.size() - 1; i >= 0; i--) {
      // 判定元素大小
      while (!s.empty() && s.top() <= nums2[i]) {
        // 弹出nums2[i]小的元素
        s.pop();
      }
      // 如果栈中有元素，一定比nums2[i]大，否则标记为-1
      next_greater[nums2[i]] = s.empty() ? -1 : s.top();
      s.push(nums2[i]);
    }
    vector<int> result;
    for (int j = 0; j < nums1.size(); ++j) {
      result.push_back(next_greater[nums1[j]]);
    }
    return result;
  }
};
