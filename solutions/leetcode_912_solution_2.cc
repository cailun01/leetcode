#include "headers.h"
/* 
快速排序

快速排序的主要思想是通过划分将待排序的序列分成前后两部分，其中前一部分的数据都比后一部分的数据要小，
然后再递归调用函数对两部分的序列分别进行快速排序，以此使整个序列达到有序。

我们定义函数 randomized_quicksort(nums, l, r) 为对 nums 数组里[l,r]的部分进行排序，
每次先调用 randomized_partition 函数对 nums 数组里 [l,r] 的部分进行划分，并返回分界值的下标 pos，
然后按上述将的递归调用 randomized_quicksort(nums, l, pos - 1) 和 randomized_quicksort(nums, pos + 1, r) 即可。

那么核心就是划分函数partition的实现了，划分函数一开始需要确定一个分界值（我们称之为主元 pivot)，然后再进行划分。
而主元的选取有很多种方式，这里我们采用随机的方式，对当前划分区间 [l,r] 里的数等概率随机一个作为我们的主元，
再将主元放到区间末尾，进行划分。

整个划分函数partition主要涉及两个指针 i 和 j，一开始 i = l - 1，j = l。
我们需要实时维护两个指针使得任意时候，对于任意数组下标 k，我们有如下条件成立：

1. l <= k <= i, nums[k] <= pivot
2. i + 1 <= k <= j - 1, nums[k] > pivot
3. k == r, nums[k] == pivot

我们每次移动指针 j ，如果 nums[j] > pivot，我们只需要继续移动指针 j ，即能使上述三个条件成立。
否则我们需要将指针 i 加一，然后交换 nums[i] 和 nums[j]，再移动指针 j 才能使得三个条件成立。

当 j 移动到 r−1 时结束循环，此时我们可以由上述三个条件知道 [l,i] 的数都小于等于主元 pivot，
[i+1,r−1] 的数都大于主元 pivot，那么我们只要交换 nums[i+1] 和 nums[r] ，即能使得 [l,i+1] 区间的
数都小于 [i+2,r] 区间的数，完成一次划分，且分界值下标为 i+1，返回即可。


快速排序的递归方式和二叉树的前序遍历类似。
    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
        return;
    }
*/
class Solution {
public:
    /*
    (1)先将A[1]存至某个临时变量pivot，并令两个下标left, 
       right分别指向序列首尾(如令left=l, right=n)。
    (2)只要right指向的元素A[right]大于pivot，就将right不断左移；
       当A[right]<=pivot时，将元素A[left]挪到left指向的元素A[left]处。
    (3)只要left指向的元素A[left]不超过pivot，就将left不断右移；
       当某个时候A[left]>pivot时，将元素A[left]挪到right指向的元素A[right]处。
    (4)重复(2)(3)直到left与right相遇，把pivot(即原A[1])放到相遇的地方

    */
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        while (left < right) {
            while (left < right && nums[right] > pivot) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot) {
                left++;
            }
            nums[right] = nums[left];
        }
        // 此时left == right
        nums[left] = pivot;
        return left;
    }

    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[l], nums[i]);
        return partition(nums, l ,r);
    }

    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
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