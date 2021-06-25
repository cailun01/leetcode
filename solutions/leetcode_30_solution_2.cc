/* 30 串联所有单词的子串

给定一个字符串s和一些长度相同的单词words。找出s中恰好可以由words中所有单词串联形成的子串的起始位置。

注意子串要与words中的单词完全匹配，中间不能有其他字符，但不需要考虑words中单词串联的顺序。

示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
示例 3：

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
*/
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    if(words.empty()) { 
      return {}; 
    }
    unordered_map<string, int> need, window;
    for(string word : words) { 
      need[word]++; 
    }
    // 字符串的长度
    int word_len = words[0].size();
    // words中字符串的个数
    int num_words = words.size();
    vector<int> ans;
    for (int k = 0; k < word_len; k++) {
    // 窗口分别从0, 1, ... word_len - 1开始
      int left = k, right = k;
      while (left < s.size() - num_words * word_len + 1) {

        // num_words * word_len是想要的串联子串的总长
        // 在滑动窗口时，随时检查不符合要求的情况
        // 等到符合要求时，right == left + num_words * word_len，退出循环。
        while (right < left + num_words * word_len) {
          string temp = s.substr(right, word_len);
          // 因为words中的字符串是串联的，所以每个temp都要加入到window中
          window[temp]++;
          right += word_len;
          if (need.find(temp) == need.end()) {
            // 情况二，有words中不存在的单词
            left = right; // left加速右移
            window.clear();
            break;
          }
          if (window[temp] > need[temp]) {
            // 情况三，子串中temp数量超出所需数目
            while (window[temp] > need[temp]) {
              window[s.substr(left, word_len)]--;
              left += word_len; // 对left加速
            }
            break;
          }                   
        } // end while (right < left + num_words * word_len)

        // 正确匹配，由于情况二和三都对i加速了，
        // left和right之间正好有所需的字符串相连
        if (right == left + word_len * num_words) {
          ans.push_back(left);
          window[s.substr(left, word_len)]--;
          left += word_len;//i正常前进
        }
      }
      window.clear();
    }
    return ans;
  }
};
