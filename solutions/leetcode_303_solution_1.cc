#include "headers.h"

//暴力解法

class NumArray {
public:
    NumArray(vector<int>& nums) {
        nums_ = nums;
    }
    
    int sumRange(int i, int j) {
        int res = 0;
        for (int idx = i; idx <= j; ++idx) {
            res += nums_[idx];
        }
        return res;
    }
private:
    vector<int> nums_;
};