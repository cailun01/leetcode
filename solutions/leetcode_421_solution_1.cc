/* 421. 数组中两个数的最大异或值
给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。

进阶：你可以在 O(n) 的时间解决这个问题吗？

示例 1：
输入：nums = [3,10,5,25,2,8]
输出：28
解释：最大运算结果是 5 XOR 25 = 28.

示例 2：
输入：nums = [0]
输出：0

示例 3：
输入：nums = [2,4]
输出：6

示例 4：
输入：nums = [8,10,2]
输出：10

示例 5：
输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
输出：127
*/

class Trie {
private:
  Trie* next[2] = {nullptr};
public:
  Trie(){}
  // 在前缀树中插入值x
  void insert(int x) {
    Trie *root = this;
    // 高位存储来Trie的前面，所以我们从左向右存储
    for(int i = 30; i >= 0; i--) {
      // 取第i位的数字，30...0
      int u = x >> i & 1;
      // 若第u位为空，则创建一个新节点，然后root移动到下一个节点
      if(!root->next[u]) {
        root->next[u] = new Trie();
      }
      root = root->next[u];
    }
  } 
  // 在前缀树中寻找 x 的最大异或值
  int srearch(int x) {
    Trie *root = this;
    // res表示最大异或值，每次res*2表示左移一位，31循环后左移了31位了，+u表示加上当前的最低位数字
    int res = 0;
    for (int i = 30; i >= 0; i--) {
      int u = x >> i & 1;
      // 若 x 的第 u 位存在，我们走到相反的方向去，因为异或总是|值|相反才取最大值的
      if (root->next[!u]) {
        root = root->next[!u];
        res = res * 2 + !u;
      }
      // 相反方向的节点为空，只能顺着相同方向走了
      else { 
        root = root->next[u];
        res = res * 2 + u;
      }
    }
    // 由于上面我们得到的异或另一个数组元素，此时我们需要将这个数组元素与x想异或得到 两个数的最大异或值
    res ^= x;
    return res;
  }
};

class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    Trie *root = new Trie();
    for(auto x : nums) { 
      root->insert(x); 
    }
    int res = 0;
    for (auto x : nums) {
      res = max(res, root->srearch(x));
    }
    return res;
  }
};