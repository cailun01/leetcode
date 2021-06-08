/* 49. 字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
由于互为字母异位词的两个字符串包含的字母相同，因此两个字符串中的相同字母出现的次数一定是相同的，
可以将每个字母出现的次数使用字符串表示，作为哈希表的键。
*/
class Solution {
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
      unordered<string, vector<string>> map;

      // 统计string的各字母频次,以频次为key直接加入队列
      for (auto s : strs) {
          string sts = string(26, '0') ;
          for (auto c : s) { 
            ++sts[c - 'a'];
          }
          map[sts].push_back(s);
      }
      for (auto e : map) { 
        res.push_back(e.second); 
      }
      return res;
    }
};