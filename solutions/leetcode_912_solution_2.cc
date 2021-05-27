#include "headers.h"
/* 
快速排序

快速排序的主要思想是通过划分将待排序的序列分成前后两部分，其中前一部分的数据都比后一部分的数据要小，
然后再递归调用函数对两部分的序列分别进行快速排序，以此使整个序列达到有序。

我们定义函数 randomized_quicksort(nums, left, right) 为对 nums 数组里[left, right]的部分进行排序，
每次先调用 randomized_partition 函数对 nums 数组里 [l,r] 的部分进行划分，并返回分界值的下标 pos，
然后按上述将的递归调用 randomized_quicksort(nums, l, pos - 1) 和 randomized_quicksort(nums, pos + 1, r) 即可。

partition 函数的思路：
(1) 先将A[left]存至某个临时变量pivot，并令两个下标left和right
    分别指向序列首尾(如令left=l, right=n)。
(2) 只要right指向的元素A[right]大于pivot，就将right不断左移；
    当A[right] <= pivot时，将元素A[left]挪到left指向的元素A[left]处。
(3) 只要left指向的元素A[left]不超过pivot，就将left不断右移；
    当某个时候A[left] > pivot时，将元素A[left]挪到right指向的元素A[right]处。
(4) 重复(2)(3)直到left与right相遇，把pivot(即原A[1])放到相遇的地方

快速排序：
(1) 调整序列中的元素，使当前序列最左端的元素在调整后满足左侧所有元素均不超过该元素，右侧所有元素均大于该元素
(2) 对该元素的左侧和右侧分别递归进行(1)的调整，直到当前调整区间长度不超过1

快速排序的递归方式和二叉树的前序遍历类似。
    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            // “前序”
            int pos = randomized_partition(nums, l, r);
            // 遍历子数组
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
        return;
    }
*/


class Solution {
public:
  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    while (left < right) {
      while (left < right && nums[right] > pivot) {
        right--; // 反复左移right
      }
      nums[left] = nums[right];
      while (left < right && nums[left] <= pivot) {
        left++;  // 反复右移left
      }
      nums[right] = nums[left];
    }
    // 此时left == right
    nums[left] = pivot; // 把pivot放到left与right相遇的地方
    return left;
  }

  int randomized_partition(vector<int>& nums, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    swap(nums[l], nums[i]);
    return partition(nums, l ,r);
  }

  void randomized_quicksort(vector<int>& nums, int l, int r) {
    if (l < r) {
      // nums[l...pos-1] < nums[pos] < nums[pos+1...r]
      int pos = randomized_partition(nums, l, r);
      randomized_quicksort(nums, l, pos - 1);
      randomized_quicksort(nums, pos + 1, r);
    }
    return;
  }

  vector<int> sortArray(vector<int>& nums) {
    srand((unsigned)time(NULL));
    randomized_quicksort(nums, 0, (int)nums.size() - 1);
    return nums;
  }
};