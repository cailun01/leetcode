// 快速选择
class Solution {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[l]);
        return partition(a, l, r);
    }

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
        nums[left] = pivot;
        return left;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        // 题目要求的是「第k个最大元素」，这个元素其实就是nums升序排序后「索引」为nums.size() - k的这个元素。
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
