/* 347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]
*/

class Solution {
public:
  static bool cmp(pair<int, int>& m, pair<int, int>& n) {
    return m.second > n.second;
  }

  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> occurrences;
    for (auto& v : nums) {
      occurrences[v]++;
    }

    // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
    for (auto& [num, count] : occurrences) {
      if (q.size() == k) {
        if (q.top().second < count) {
          q.pop();
          q.emplace(num, count);
        }
      } else {
        q.emplace(num, count);
      }
    }
    vector<int> ret;
    while (!q.empty()) {
      ret.emplace_back(q.top().first);
      q.pop();
    }
    return ret;
  }
};
