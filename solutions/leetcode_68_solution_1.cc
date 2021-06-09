/* 68. 文本左右对齐
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。
必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/

/*
https://leetcode-cn.com/problems/text-justification/solution/text-justification-by-ikaruga/
*/
class Solution {
public:
  string fillWords(vector<string>& words, int begin, int end, int maxWidth, bool lastLine = false) {
    // 本行有wordCount个单词
    int wordCount = end - begin + 1;
    // spaceCount表示本行有多少额外空格，额外空格就是正常书写用不到的空格
    // 减去每个单词尾部空格， +1 是最后一个单词的尾部空格的特殊处理（即结尾虚拟了一个空格）
    int spaceCount = maxWidth + 1 - wordCount;
    for (int i = begin; i <= end; i++) {
      spaceCount -= words[i].size();  // 减去所有单词的长度
    }
    // 词尾空格
    int spaceSuffix = 1;
    // spaceAvg是额外空格的平均值，wordCount - 1是单词之间的间隙的数目
    // 每个间隙一定会分配spaceAvg个空格
    int spaceAvg = (wordCount == 1) ? 1 : spaceCount / (wordCount - 1);
    // 额外空格的余数。给每个间隙都分配了spaceAvg个空格之后，
    // 把余下的spaceExtra依次的放到第一个、第二个、第三个间隙中
    int spaceExtra = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1);
    string ans;
    for (int i = begin; i < end; i++) {
      ans += words[i];    // 填入单词
      if (lastLine) {
        // 特殊处理最后一行
        fill_n(back_inserter(ans), 1, ' ');
        continue;
      }
      // 根据计算结果补上空格
      fill_n(back_inserter(ans), spaceSuffix + spaceAvg + ((i - begin) < spaceExtra), ' ');  
    }
    ans += words[end];   // 填入最后一个单词
    fill_n(back_inserter(ans), maxWidth - ans.size(), ' '); // 补上这一行最后的空格
    return ans;
  }

  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    // 每个字符串加上空格的长度
    int cnt = 0;
    int begin = 0;
    for (int i = 0; i < words.size(); i++) {
      cnt += words[i].size() + 1;
      if (i + 1 == words.size() || cnt + words[i + 1].size() > maxWidth) {   
        // 如果是最后一个单词，或者加上下一个词就超过长度了，即可凑成一行
        ans.push_back(fillWords(words, begin, i, maxWidth, i + 1 == words.size()));
        begin = i + 1;
        cnt = 0;
      }
    }
    return ans;
  }
};