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