#include "headers.h"


class Solution {
public:
    void sortArray(vector<int> &nums) {
        // 构建大顶堆,从第一个非叶子节点开始,向左依次进行下沉操作
        for (int i = nums.size() / 2; i >= 0; --i) {
            siftdown(nums, i, nums.size());
        }
        // 进行出堆操作,相当于pop()
        for (int i = nums.size() - 1; i > 0; --i) {
            swap(nums[0], nums[i]); // 出堆(将最大值放置数组尾,堆size - 1)
            siftdown(nums, 0, i); // 将根执行下沉操作
        }
    }

    void siftdown(vector<int> &nums, int root, int size) {
        /**
         * 构造大顶堆的下浮操作
         */
        while (2 * root + 1 < size) { // 当p存在孩子时
            int c1 = 2 * root + 1; // p节点的左孩子
            int c2 = 2 * root + 2; // p节点的右孩子
            int c = (c2 < size && nums[c2] > nums[c1]) ? c2 : c1; // c是值最大的孩子节点
            if (nums[c] > nums[root]) { // 若孩子节点大于父亲节点,交换位置
                swap(nums[c], nums[root]);
            } else {
                break; // 该点满足堆条件,又因为下方已经成堆,所以不必向下建堆
            }
            /**
             * 若此时节点不是最大值,则有可能也小于
             * <以该节点为根的下一个子堆>的孩子节点
             * 所以需要将该节点也进行一次下沉操作
             */
            root = c;
        }
    }
};