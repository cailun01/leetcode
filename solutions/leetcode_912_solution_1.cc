#include "headers.h"
/* 归并排序的递归解法

归并排序（MERGE-SORT）是利用归并的思想实现的排序方法，该算法采用经典的分治（divide-and-conquer）策略
（分治法将问题分(divide)成一些小的问题然后递归求解，而治(conquer)的阶段则将分的阶段得到的各答案"修补"在一起，
即分而治之)。

将序列两两分组，将序列归并为n/2个组，组内单独排序，然后将这些组再两两归并，生成n/4个组，组内再单独排序，以此类推。
*/
class Solution {
public:
  vector<int> temp;
  // 将数组nums的[l1, r1]和[l2, r2]合并为有序区间(此处l2 = r1 + 1)
  void merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
    // 对于已经有序的子序列nums[l1...r1]和nums[l2...r2]，合并为最终序列
    // 遍历子序列，将较小的值放入temp
    int index = 0;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2) {
      if (nums[i] <= nums[j]) {
        temp[index++] = nums[i++];
      } else {
        temp[index++] = nums[j++];
      }
    }
    //将左边剩余元素填充进temp中
    while (i <= r1) {
      temp[index++] = nums[i++];
    }
    //将右序列剩余元素填充进temp中
    while (j <= r2) {
      temp[index++] = nums[j++];
    }
    //将temp中的元素全部拷贝到原数组中
    for (int k = 0; k < index; ++k) {
      nums[l1 + k] = temp[k];
    }
    return;
  }
  void merge_sort(vector<int>& nums, int left, int right) {
    if (left < right) {
      int mid = (left + right) / 2;
      merge_sort(nums, left, mid);
      merge_sort(nums, mid + 1, right);
      merge(nums, left, mid, mid + 1, right);
    }
    return;
  }
  vector<int> sortArray(vector<int>& nums) {
    temp.resize(nums.size(), 0);
    merge_sort(nums, 0, nums.size() - 1);
    return nums;
  }
};