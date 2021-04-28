#include "headers.h"
// 堆排序
class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int& i : nums) {
            pq.push(i);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};