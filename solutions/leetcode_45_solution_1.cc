/*
在遍历数组时，我们不访问最后一个元素，这是因为在访问最后一个元素之前，
我们的边界一定大于等于最后一个位置，否则就无法跳到最后一个位置了。
如果访问最后一个元素，在边界正好为最后一个位置的情况下，我们会增加一次「不必要的跳跃次数」，
因此我们不必访问最后一个元素。
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0;
        int farthest = INT_MIN;
        int num_jumps = 0;
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(nums[i] + i, farthest);
            if (end == i) {
                end = farthest;
                ++num_jumps;
            }
        }
        return num_jumps; 
    }
};