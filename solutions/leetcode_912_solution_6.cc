#include "headers.h"
/* 912 排序数组

堆排序
堆排序的思想就是先将待排序的序列建成大顶堆，使得每个父节点的元素大于等于它的子节点。
建堆过程：
    每次调整都是把节点从上往下调整。总是将当前节点root与他的左右孩子比较（如果有的话），
    假如孩子中存在权值比节点root权值大的，就将其中权值最大的那个孩子节点与节点root交换；
    交换完毕后继续让节点root与孩子比较，直到节点root的孩子的权值都比节点root的权值小
    或root不存在孩子节点。

此时整个序列最大值即为堆顶元素，我们将其与末尾元素交换，使末尾元素为最大值，
然后再调整堆顶元素使得剩下的 n−1 个元素仍为大顶堆，再重复执行以上操作我们即能得到一个有序的序列。
*/

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    // 构建大顶堆,从第一个非叶子节点开始,向左依次进行下沉操作
    // 第一个非叶子节点的索引是nums.size() / 2 - 1
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
      siftdown(nums, i, nums.size());
    }
    // 进行出堆操作,相当于pop()
    for (int i = nums.size() - 1; i > 0; --i) {
      swap(nums[0], nums[i]); // 出堆(将最大值放置数组尾, 堆size - 1)
      siftdown(nums, 0, i); // 将根执行下沉操作
    }
    return nums;
  }

  void siftdown(vector<int> &nums, int root, int size) {
    /* 构造大顶堆的下浮操作 */
    while (2 * root + 1 < size) { // 当root存在孩子时
      int l_son = 2 * root + 1; // root节点的左孩子
      int r_son = 2 * root + 2; // root节点的右孩子
      // max_son是值最大的孩子节点
      int max_son = 0;
      // 如果右孩子存在(r_son < size)，且右孩子的值大于左孩子
      if (r_son < size && nums[r_son] > nums[l_son]) {
        max_son = r_son;
      } else {
        max_son = l_son;
      }
      if (nums[max_son] > nums[root]) { 
        // 若孩子节点大于父亲节点,交换位置
        swap(nums[max_son], nums[root]);
        root = max_son;
      } else {
        break; // 该点满足堆条件,又因为下方已经成堆,所以不必向下建堆
      }
    }
  }
};