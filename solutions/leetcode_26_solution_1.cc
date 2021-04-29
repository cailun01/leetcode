class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) { 
            return 0;
        }
        int length = nums.size();
        int fast = 0, slow = 0;
        while (fast < length) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow + 1;
    }
};