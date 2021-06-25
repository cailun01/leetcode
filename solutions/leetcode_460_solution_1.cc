/* 460 LFU缓存
请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

实现 LFUCache 类：
LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
int get(int key) - 如果键存在于缓存中，则获取键的值，否则返回 -1。
void put(int key, int value) - 如果键已存在，则变更其值；如果键不存在，请插入键值对。
当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，
当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近最久未使用 的键。
注意「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。

为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。

当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，
使用计数器的值将会递增。


示例：

输入：
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
输出：
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

解释：
// cnt(x) = 键 x 的使用计数
// cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
LFUCache lFUCache = new LFUCache(2);
lFUCache.put(1, 1);   // cache=[1,_], cnt(1)=1
lFUCache.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lFUCache.get(1);      // 返回 1
                      // cache=[1,2], cnt(2)=1, cnt(1)=2
lFUCache.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                      // cache=[3,1], cnt(3)=1, cnt(1)=2
lFUCache.get(2);      // 返回 -1（未找到）
lFUCache.get(3);      // 返回 3
                      // cache=[3,1], cnt(3)=2, cnt(1)=2
lFUCache.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                      // cache=[4,3], cnt(4)=1, cnt(3)=2
lFUCache.get(1);      // 返回 -1（未找到）
lFUCache.get(3);      // 返回 3
                      // cache=[3,4], cnt(4)=1, cnt(3)=3
lFUCache.get(4);      // 返回 4
                      // cache=[3,4], cnt(4)=2, cnt(3)=3
 

提示：

0 <= capacity, key, value <= 104
最多调用 105 次 get 和 put 方法
 

进阶：你可以为这两种操作设计时间复杂度为 O(1) 的实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lfu-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


struct Node {
  Node(int k, int v) {
    key = k;
    val = v;
  }
  Node *next, *prev;
  int key, val;
};

class DoubleList {
public:
  DoubleList() : 
      head(new Node(0, 0)), tail(new Node(0, 0)), size_(0) {
    head->next = tail;
    tail->prev = head;
  }

  void add_last(Node* x) {
    x->prev = tail->prev;
    x->next = tail;
    tail->prev->next = x;
    tail->prev = x;
    ++size_;
  }

  void remove(Node* x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
    --size_;
  }

  Node* remove_first() {
    if (head->next == tail) {
      return nullptr;
    }
    Node* first = head->next;
    remove(first);
    return first;
  }

  int size() const {
    return size_;
  }

  int size() {
    return size_;
  }
  
private:
  Node *head, *tail;
  int size_;
};

class LFUCache {
public:
    LFUCache(int capacity) {
      cap = capacity;
      min_frequency = 0;
    }
    
    int get(int key) {
      if (key_to_val.find(key) == key_to_val.end()) {
        return -1;
      }
      increase_frequency(key);
      return key_to_val[key]->val;
    }
    
    void put(int key, int value) {
      if (cap <= 0) {
          return;
      }
      /* 若 key 已存在，修改对应的 val 即可 */
      if (key_to_val.find(key) != key_to_val.end()) {
        key_to_val[key]->val = value;
        increase_frequency(key);
        return;
      }
      /* key 不存在，需要插入 */
      /* 容量已满的话需要淘汰一个 freq 最小的 key */
      if (cap <= key_to_val.size()) {
        remove_min_frequency_key();
      }
      Node* node = new Node(key, value);
      key_to_val[key] = node;
      key_to_frequency[key] = 1;
      if (frequency_to_keys.find(1) == frequency_to_keys.end()) {
          DoubleList* new_key_list = new DoubleList();
          new_key_list->add_last(node);
          frequency_to_keys.insert({1, new_key_list});
      } else {
          frequency_to_keys[1]->add_last(node);
      }
      // 插入新 key 后最小的 freq 肯定是 1
      min_frequency = 1;
    }
    
    // 修改key对应的freq
    void increase_frequency(int key) {
      int frequency = key_to_frequency[key];
      Node* key_node = key_to_val[key];
      int frequency_plus_one = frequency + 1;
      key_to_frequency[key] = frequency_plus_one;
      
      // 将 key 从 freq 对应的列表中删除
      frequency_to_keys[frequency]->remove(key_node);
      
      // 将 key 加入 freq + 1 对应的列表中
      if (frequency_to_keys.find(frequency_plus_one) == frequency_to_keys.end()) {
          DoubleList* new_key_list = new DoubleList();
          new_key_list->add_last(key_node);
          frequency_to_keys.insert({frequency_plus_one, new_key_list});
      } else {
          frequency_to_keys[frequency_plus_one]->add_last(key_node);
      }
      
      // 如果 freq 对应的列表空了，移除这个 freq
      if (frequency_to_keys[frequency]->size() == 0) {
        frequency_to_keys.erase(frequency);
        // 如果这个 freq 恰好是 minFreq，更新 minFreq
        if (frequency == min_frequency) {
          min_frequency++;
        }
      }
    }

    void remove_min_frequency_key() {
      // freq 最小的 key 列表
      DoubleList* key_list = frequency_to_keys[min_frequency];
      Node* deleted_node = key_list->remove_first();
      // 其中最先被插入的那个 key 就是该被淘汰的 key
      int deleted_key = deleted_node->key;
      if (key_list->size() == 0) {
        frequency_to_keys.erase(min_frequency);
      }
      key_to_val.erase(deleted_key);
      key_to_frequency.erase(deleted_key);
    }

private:
  // 记录 LFU 缓存的最大容量
  int cap;
  // 记录最小的频次
  int min_frequency;
  // key 到 Node* 的映射
  unordered_map<int, Node*> key_to_val;
  // key 到 freq 的映射
  unordered_map<int, int> key_to_frequency;
  // freq 到 key 列表的映射
  unordered_map<int, DoubleList*> frequency_to_keys;
};
