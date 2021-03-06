/* 316 去除重复字母
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同

示例 1：

输入：s = "bcabc"
输出："abc"

示例 2：
输入：s = "cbacdcbc"
输出："acdb"
*/


/* 题目有3个要求：
要求一、要去重。
要求二、去重字符串中的字符顺序不能打乱s中字符出现的相对顺序。
要求三、在所有符合上一条要求的去重字符串中，字典序最小的作为最终结果。

满足要求一、通过in_stack这个布尔数组做到栈stk中不存在重复元素。
满足要求二、我们顺序遍历字符串s，通过「栈」这种顺序结构的 push/pop 操作记录结果字符串，
保证了字符出现的顺序和s中出现的顺序一致。
满足要求三、我们用类似单调栈的思路，
配合计数器count不断 pop 掉不符合最小字典序的字符，保证了最终得到的结果字典序最小。
我们用了一个计数器count，当字典序较小的字符试图「挤掉」栈顶元素的时候，
在count中检查栈顶元素是否是唯一的，只有当后面还存在栈顶元素的时候才能挤掉，否则不能挤掉。
*/
class Solution {
public:
  string removeDuplicateLetters(string s) {
    if (s.size() == 1) {
        return s;
    }
    // 存放去重的结果
    stack<char> stk;
    // 维护一个计数器记录字符串中字符的数量
    vector<int> count(26, 0);
    // 布尔数组初始值为 false，记录栈中是否存在某个字符
    vector<bool> in_stack(26, false);
    
    for (const auto& c : s) {
      count[c - 'a']++;
    }

    for (const auto& c : s) {
      // 每遍历过一个字符，都将对应的计数减一
      count[c - 'a']--;
      
      // 如果字符 c 存在栈中，直接跳过
      if (in_stack[c - 'a']) {
          continue;
      }
      // 插入之前，和栈顶的元素比较一下大小
      // 如果字典序比前面的小，pop 前面的元素
      while (!stk.empty() && stk.top() > c) {
        // 但是，如果之后不存在栈顶元素了，则停止 pop
        if (count[stk.top() - 'a'] == 0) {
          break;
        }
        // 弹出栈顶元素，并把该元素标记为不在栈中。若之后还有，则可以 pop
        in_stack[stk.top() - 'a'] = false;
        stk.pop();
      }
      // 把c压入栈，并把对应位置设为true
      stk.push(c);
      in_stack[c - 'a'] = true;
    }
    string result;
    while (!stk.empty()) {
      result.push_back(stk.top());
      stk.pop();
    }
    // 栈中元素插入顺序是反的，需要 reverse 一下
    reverse(result.begin(), result.end());
    return result;
  }
};
