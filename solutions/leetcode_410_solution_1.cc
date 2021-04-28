class Solution {
public:

    int split(vector<int>& nums, int max) {
        int count = 1;
        // 记录每个子数组的元素和
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] > max) {
                // 如果当前子数组和大于 max 限制
                // 则这个子数组不能再添加元素了
                count++;
                sum = nums[i];
            } else {
                // 当前子数组和还没达到 max 限制
                // 还可以添加元素
                sum += nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low < high) {
            int mid = low + (high - low) / 2;
            // 根据分割子数组的个数收缩搜索区间
            int n = split(nums, mid);
            if (n == m) {
                // 收缩右边界，达到搜索左边界的目的
                high = mid;
            } else if (n < m) {
                // 最大子数组和上限高了，减小一些
                high = mid;
            } else if (n > m) {
                // 最大子数组和上限低了，增加一些
                low = mid + 1;
            }
        }
        return low;
    }
};