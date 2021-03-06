/* 解决这道题的核心其实在于了解格雷编码是如何形成的。

第一个点，如果我们有n bits，那么相应的我们会有 2^n个格雷编码，假设 n=2，
那么我们相应的会有 4 个格雷编码。所以我们先求出有多少个格雷编码也就是 2^n，
等价于 1 << n 也就是将 1 向左移动 n 位。假设n为2，那么0001向左移动两位就是0100也就变成了4.
第二个点，格雷编码如何形成。同样以n = 2解析。
公式为 i ^ i/2 (即 i ^ i >> 1)，右移>>的优先级高于按位异或^
0 ^ 0 = 00 ^ 00 = 00 = 0 计算(i/2): 0/2 = 0
1 ^ 0 = 01 ^ 00 = 01 = 1 计算(i/2): 1/2 = 0
2 ^ 1 = 10 ^ 01 = 11 = 3 计算(i/2): 2/2 = 1
3 ^ 1 = 11 ^ 01 = 10 = 2 计算(i/2): 3/2 = 1
*/

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> ans;
    int powN = 1 << n;
    for(int i = 0; i < powN; ++i) {
      ans.push_back(i^i>>1);
    }
    return ans;
  }
};