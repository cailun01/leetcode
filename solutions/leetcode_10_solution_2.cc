class Solution {
public:
  bool isMatch(string s, string p) {
      return dp(0, 0, s, p);
  }

  bool dp(int i, int j, const string& s, const string& p) {
      string key = serialize(i, j);
      if (memo.find(key) != memo.end()) {
        return memo[key];
      }

      if (j == p.size()) {
        return i == s.size();
      }

      // p[j] == s[i]或者p[j]是'.'，意味着字符匹配
      bool first_letter_match = i < s.size() && \
          (p[j] == s[i] || p[j] == '.');
      
      bool ans;
      if (j <= p.size() - 2 && p[j + 1] == '*') {
        ans = dp(i, j + 2, s, p) || (first_letter_match && dp(i + 1, j, s, p));
        // dp(i, j + 2, s, p): *匹配该字符0次，跳过该字符和*
        // (first_letter_match && dp(i + 1, j, s, p)): s[0] 和p[0]匹配，移动s
      } else {
        // 没有*的情况，继续比较后面的字符
        ans = first_letter_match && dp(i + 1, j + 1, s, p);
      }
      memo[serialize(i, j)] = ans;
      return ans;
  }
private:
  string serialize(int i, int j) {
    return to_string(i) + string("_") + to_string(j);
  }
  unordered_map<string, bool> memo;
};