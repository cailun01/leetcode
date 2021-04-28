#include "headers.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int new_ans = 0;
        int original = x;
        int temp = 0;
        while (x != 0) {
            temp = x % 10;
            x /= 10;
            if (new_ans > INT_MAX / 10 || (new_ans == INT_MAX / 10 + 7)) {
                return false;
            }
            new_ans = new_ans * 10 + temp; 
        }
        return original == new_ans;
    }
};