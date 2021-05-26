/*
给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的每一项或者为一个整数，或者是另一个列表。其中列表的元素也可能是整数或是其他列表。


示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回 false，next 返回的元素的顺序应该是: [1,4,6]。
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/** 每次调用next之前，先调用hasNext
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/*
我们可以用一个栈来代替方法一中的递归过程。

具体来说，用一个栈来维护深度优先搜索时，从根节点到当前节点路径上的所有节点。
由于非叶节点对应的是一个列表，我们在栈中存储的是指向列表当前遍历的元素的指针（下标）。
每次向下搜索时，取出列表的当前指针指向的元素并将其入栈，同时将该指针向后移动一位。
如此反复直到找到一个整数。循环时若栈顶指针指向了列表末尾，则将其从栈顶弹出。

1. 首先我们将nestedList里的 NestedInteger object的begin()与end()推进堆。
假设输入是nestedList = [ [1,1], 2, [1,2] ]，注意这是 3 个元素都是NestedInteger objects;
我们将nestedList两个迭代器begin()和end()放入栈。

NestedIterator(vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
}

2. 因为保证调用 next 之前会调用 hasNext，所以我们在hasNext保证下一个元素是整数。

如果此时我们用stk.top().first来call isInteger()的话返回的是false! 为什么？
因为此时stk.top().first这个iterator是指向 [1,1]这个NestedInteger object，因此我们需要
再往这个object的里面走一层，取得 [1,1]的 iterator。

3. 代码实现中，我们用
auto &p = stk.top();
auto &lst = p.first++->getList();
获得[1,1]，再让迭代器右移，指向元素2，然后把[1, 1]的迭代器放入栈：
stk.emplace(lst.begin(), lst.end());
这样栈顶元素就指向了int型
*/

class NestedIterator {
private:
  // pair 中存储的是列表的当前遍历位置，以及一个尾后迭代器用于判断是否遍历到了列表末尾
  stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    stk.emplace(nestedList.begin(), nestedList.end());
  }

  int next() {
    // 由于保证调用 next 之前会调用 hasNext，直接返回栈顶列表的当前元素，然后迭代器指向下一个元素
    return stk.top().first++->getInteger();
  }

  bool hasNext() {
    while (!stk.empty()) {
      auto &p = stk.top();
      if (p.first == p.second) { // 遍历到当前列表末尾，出栈
        stk.pop();
        continue;
      }
      if (p.first->isInteger()) {
        return true;
      }
      // 若当前元素为列表，则将其入栈，且迭代器指向下一个元素
      auto &lst = p.first++->getList();
      stk.emplace(lst.begin(), lst.end());
    }
    return false;
  }
};