/* 97. 交错字符串
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
提示：a + b 意味着字符串 a 和 b 连接。

示例 1：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true

示例 2：
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出：false

示例 3：
输入：s1 = "", s2 = "", s3 = ""
输出：true
*/

class Solution {
  bool DFS(string &s1, string &s2, string &s3, 
           int i/*s1 index*/, int j/*s2 index*/, int k/*s3 index*/, 
           vector<vector<int>>& memory) {
    if (memory[i][j] != -1) { 
      return memory[i][j];
    }
    if (k == s3.size()) {
      memory[i][j] = 1;
      return true;
    }
    bool res = false;
    if (i < s1.size() && s1[i] == s3[k]) {
      res = DFS(s1, s2, s3, i + 1, j, k + 1, memory);
    }
    if (j < s2.size() && s2[j] == s3[k]) {
      // 注意此处，主要s1或s2匹配上就行。
      res = res || DFS(s1, s2, s3, i, j + 1, k + 1, memory);
    }
    memory[i][j] = res ? 1 : 0;
    return res;
  }
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    // memory[i][j] == -1, 未访问过i,j
    // memory[i][j] == 0, 访问过i,j, false
    // memory[i][j] == 1, 访问过i,j, true
    vector<vector<int>> memory(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return DFS(s1, s2, s3, 0/*s1 index*/, 0/*s2 index*/, 0/*s3 index*/, memory);
  }
};
