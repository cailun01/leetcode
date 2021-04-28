#include "headers.h"
// 暴力解法，会超时
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int cur_height = heights.at(i);
            int left = i;
            while (left > 0 && heights[left - 1] >= cur_height) {
                --left;
            }

            int right = i;
            while (right < heights.size() - 1 && heights[right + 1] >= cur_height) {
                ++right;
            }
            int width = right - left + 1;
            max_area = max(max_area, cur_height * width);
        }
        return max_area;
    }
};