/* 380 常数时间插入、删除和获取随机元素
设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。

insert(val)：当元素 val 不存在时，向集合中插入该项。
remove(val)：元素 val 存在时，从集合中移除该项。
getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
示例 :

// 初始化一个空的集合。
RandomizedSet randomSet = new RandomizedSet();

// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomSet.insert(1);

// 返回 false ，表示集合中不存在 2 。
randomSet.remove(2);

// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomSet.insert(2);

// getRandom 应随机返回 1 或 2 。
randomSet.getRandom();

// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomSet.remove(1);

// 2 已在集合中，所以返回 false 。
randomSet.insert(2);

// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
randomSet.getRandom();
*/
/*
1、插入，删除，获取随机元素这三个操作的时间复杂度必须都是 O(1)。
2、getRandom方法返回的元素必须等概率返回随机元素，也就是说，如果集合里面有n个元素，每个元素被返回的概率必须是1/n。

插入、删除操作，unordered_map时间复杂度是O(1)。但getRandom达不到O(1)。
LRU,LFU用到的哈希链表，只给哈希表增加了有序性，底层是链表，仍无法在O(1)的时间内访问某个元素。

如果想「等概率」且「在 O(1) 的时间」取出元素，一定要满足：底层用数组实现，且数组必须是紧凑的。

这样我们就可以直接生成随机数作为索引，从数组中取出该随机索引对应的元素，作为随机元素。

但如果用数组存储元素的话，插入，删除的时间复杂度怎么可能是 O(1) 呢？

可以做到！对数组尾部进行插入和删除操作不会涉及数据搬移，时间复杂度是 O(1)。

所以，如果我们想在 O(1) 的时间删除数组中的某一个元素val，可以先把这个元素交换到数组的尾部，然后再pop掉。

交换两个元素必须通过索引进行交换对吧，那么我们需要一个哈希表valToIndex来记录每个元素值对应的索引。
*/

class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() {

  }
  
  /** Inserts a value to the set. Returns true if the set 
   * did not already contain the specified element. */
  bool insert(int val) {
    // 若 val 已存在，不用再插入
    if (val_to_index.find(val) != val_to_index.end()) {
      return false;
    }
    // 若 val 不存在，插入到 nums 尾部，
    // 并记录 val 对应的索引值
    val_to_index.insert({val, nums.size()});
    nums.push_back(val);
    return true;
  }
  
  /** Removes a value from the set. Returns true if the set 
   * contained the specified element. */
  bool remove(int val) {
    // 若 val 不存在，不用再删除
    if (val_to_index.find(val) != val_to_index.end()) {
      return false;
    }
    // 先拿到 val 的索引
    int index = val_to_index[val];
    // 将最后一个元素对应的索引修改为 index
    val_to_index[nums.back()] = index;
    // 交换 val 和最后一个元素
    swap(nums[index], nums.back());
    // 在数组中删除元素 val
    nums.pop_back();
    // 删除元素 val 对应的索引
    val_to_index.erase(val);
    return true;
  }
  
  /** Get a random element from the set. */
  int getRandom() {
    // 随机获取 nums 中的一个元素
    return nums[rand() % nums.size()];
  }

private:
  // 存储元素的值
  vector<int> nums;
  // 记录每个元素对应在 nums 中的索引
  unordered_map<int, int> val_to_index;
};
