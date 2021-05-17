#include "headers.h"
// 堆排序
class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // 小顶堆
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int& i : nums) {
            pq.push(i);
            if (pq.size() > k) {
                // 被弹出的元素都是较小的
                pq.pop();
            }
        }
        return pq.top();
    }
};