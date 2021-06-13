class Solution {
public:
  int helper(const string& s, int i, int j) {
    int num = 0;
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
      ++num;
      --i, ++j;
    }
    return num;
  }
  int countSubstrings(string s) {
    if (s.size() == 0 || s.size() == 1) {
      return s.size();
    }
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
      int num1 = helper(s, i, i);
      result += num1;
      if (i < s.size() - 1) {
        int num2 = helper(s, i, i + 1);
        result += num2;
      }
    }
    return result;
  }
};