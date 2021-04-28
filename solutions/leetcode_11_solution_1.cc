#include "headers.h"

// two pointers

class Solution {
public:
  int maxArea(vector<int>& height) {
    int max_area = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r) {
      max_area = max(min(height[l], height[r]) * (r - l), max_area);
      if (height[l] < height[r]) {
        l = l + 1;
      } else {
        r = r - 1;
      }
    }
    return max_area;
  }
};