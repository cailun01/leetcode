/*
运用你所掌握的数据结构，设计和实现一个LRU(最近最少使用)缓存机制 。
实现LRUCache类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，
则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删
除最久未使用的数据值，从而为新的数据值留出空间。
 
进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例：

输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4

*/

// 双链表的节点
struct Node {
  Node(int k, int v) {
    key = k;
    val = v;
  }
  Node *next, *prev;
  int key, val;
};

class DoubleList {
private:
  // 头尾虚节点
  Node *head, *tail;
  // 链表元素个数
  int size_;
public:
  DoubleList() : 
      head(new Node(0, 0)), tail(new Node(0, 0)), size_(0) {
    // 初始化双向链表
    head->next = tail;
    tail->prev = head;
  }

  // 在链表尾部添加节点x，其时间复杂的为O(1)
  void add_last(Node* x) {
    x->prev = tail->prev;
    x->next = tail;
    tail->prev->next = x;
    tail->prev = x;
    ++size_;
  }

  // 删除链表中的x节点(x一定存在)
  // 时间复杂度为O(1)
  void remove(Node* x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
    --size_;
  }

  // 删除链表的第一个节点并返回，时间复杂度为O(1)
  Node* remove_first() {
    if (head->next == tail) {
      return nullptr;
    }
    Node* first = head->next;
    remove(first);
    return first;
  }

  // 链表大小，时间复杂度为O(1)
  int size() {
    return size_;
  }
};

class LRUCache {
private:
  int cap;
  unordered_map<int, Node*> map;
  DoubleList cache;
public:
  LRUCache(int capacity) {
    cap = capacity;
  }

  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;
    }
    // 将该数据提升为最近使用的
    make_recently(key);
    return map[key]->val;
  }

  void put(int key, int val) {
    if (map.find(key) != map.end()) {
      // 删除旧的数据
      delete_key(key);
      // 新插入的数据为最近使用的数据
      add_recently(key, val);
      return;
    }

    if (cap == cache.size()) {
      // 删除最久未使用的元素
      remove_least_recently();
    }
    // 添加为最近使用的元素
    add_recently(key, val);
  }
private:
  // 将某个key提升为最近使用的。
  void make_recently(int key) {
    Node* x = map[key];
    cache.remove(x);
    cache.add_last(x);
  }

  // 添加最近使用的元素
  void add_recently(int key, int val) {
    Node* x = new Node(key, val);
    cache.add_last(x);
    map[key] = x;
  }

  // 删除某一个key
  void delete_key(int key) {
    Node* x = map[key];
    cache.remove(x);
    map.erase(key);
  }

  // 删除最久未用的元素
  void remove_least_recently() {
    // 链表头部第一个元素就是最久未使用的
    Node* deleted_node = cache.remove_first();
    int deleted_key = deleted_node->key;
    map.erase(deleted_key);
  }
};