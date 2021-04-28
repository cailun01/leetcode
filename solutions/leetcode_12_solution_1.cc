#include "headers.h"

class Solution {
public:
    string intToRoman(int num) {
        string result;
        // 900, 400, 90, 40, 9, 4是特殊情况
        vector<int> store = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int storeSize = store.size();
        //贪心法
        for (int i = 0; i < storeSize; i++) {
            while (num >= store[i]) {
                result.append(strs[i]);
                num -= store[i];
            }
        }
        return result;
    }
};

