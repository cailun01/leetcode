#include "headers.h"
// 堆（优先级队列）
class KthLargest {
    int K;
    priority_queue<int, vector<int>, greater<int>> pq; // 优先级队列（小顶堆）
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }       
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }
};
