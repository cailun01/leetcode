/* 208. 实现 Trie (前缀树)
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。
这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：
Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，
返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，
返回 true ；否则，返回 false 。

示例：

输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True

提示：
1 <= word.length, prefix.length <= 2000
word 和 prefix 仅由小写英文字母组成
insert、search 和 startsWith 调用次数 总计 不超过 3 * 104 次
*/

class Trie {
private:
  vector<Trie*> next;
  bool is_end;
public:
  /** Initialize your data structure here. */
  Trie() : next(26, nullptr), is_end(false) {

  }
  
  /** Inserts a word into the trie. */
  /*
  这个操作和构建链表很像。首先从根结点的子结点开始与word第一个字符进行匹配，
  一直匹配到前缀链上没有对应的字符，这时开始不断开辟新的结点，
  直到插入完word的最后一个字符，同时还要将最后一个结点isEnd = true;，表示它是一个单词的末尾。
  */
  void insert(string word) {
    Trie* node = this;
    for (auto c : word) {
      if (node->next[c - 'a'] == nullptr) {
        node->next[c - 'a'] = new Trie();
      }
      node = node->next[c - 'a'];
    }
    node->is_end = true;
  }
  
  /** Returns if the word is in the trie. */
  /*
  从根结点的子结点开始，一直向下匹配即可，如果出现结点值为空就返回 false，
  如果匹配到了最后一个字符，那我们只需判断 node->isEnd即可。
  */
  bool search(string word) {
    Trie* node = this;
    for (auto c : word) {
      if (node->next[c - 'a'] == nullptr) {
        return false;
      }
      node = node->next[c - 'a'];
    }
    return node->is_end;
  }
  
  /** Returns if there is any word in the trie that starts with the given prefix. */
  /*
  和 search 操作类似，只是不需要判断最后一个字符结点的isEnd，
  因为既然能匹配到最后一个字符，那后面一定有单词是以它为前缀的。
  */
  bool startsWith(string prefix) {
    Trie* node = this;
    for (auto c : prefix) {
      if (node->next[c - 'a'] == nullptr) {
        return false;
      }
      node = node->next[c - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */