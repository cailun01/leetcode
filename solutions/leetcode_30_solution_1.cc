
/*
思路总结 map + 滑动窗口
wordSize：单词大小
1.用targetMap来记录words里单词和对应的数量（一个单词可能出现多次）
2.如何遍历呢？ 起始地址是 0 到 wordSize，然后按照wordSize去移动窗口，这么做的原因是能保证考虑了所有的情况
3.当前遍历次数也维持一个 currMap 来记录当前words到对应的数量，对于每次档次遍历，维持窗口left = right = 起始地址
  3.1 单词在targetMap里不存在： 不满足条件，则重置窗口，清空currMap，
  3.2 单词在targetMap里存在： 增加计数，这里需要考虑两种情况
    3.2.1 要考虑如果数量超过了targetMap里，需要去收缩窗口，即左移left
    3.2.2 如果已经每个单词都满足即等于 numWords， 则插入left作为当前的答案

https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/solution/cji-hu-shuang-bai-de-hua-dong-chuang-kou-6zch/
*/
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    int n = s.size();

    // 边缘情况
    if (n <= 0 || words.empty()) {
        return res;
    }

    // 单词的大小
    int wordSize = words[0].size();
    // 单词数量
    int numWords = words.size();
    // words的单词到次数的映射
    unordered_map<string, int> targetMap;
    for (string& word : words) {
        ++targetMap[word];
    }
    // 起点以 one_word来偏移，这样子就可以覆盖所有的情况
    for (int i = 0; i < wordSize; ++i) {
      // 记录当前统计的窗口的left和 right，以及已匹配的单词个数cnt
      int left = i;
      int right = i;
      int cnt = 0;
      // 当前窗口的映射表
      unordered_map<string, int> currMap;

      // 窗口移动
      while (right + wordSize <= n) {
        // 提取以right为起点的 wordSize为大小的单词
        string currWord = s.substr(right, wordSize);
        right += wordSize;
        if (targetMap.find(currWord) != targetMap.end()) {
          // 存在该单词
          ++currMap[currWord];
          ++cnt;
          // 需要检查窗口中当前单词数量是否超过目标字典中的单词数量，超过则要左移left来缩小窗口
          while (currMap[currWord] > targetMap[currWord]) {
            string ts = s.substr(left, wordSize);
            left += wordSize;
            --cnt;
            --currMap[ts];
          }
          if (cnt == numWords) {
            res.push_back(left);
          }
        } else {
          // 不存在单词
          left = right;
          cnt = 0;
          currMap.clear();
        }
      }
    }
    return res;
  }
};
