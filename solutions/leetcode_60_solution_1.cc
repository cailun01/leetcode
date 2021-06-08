/* 60. 排列序列
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

 

示例 1：

输入：n = 3, k = 3
输出："213"
示例 2：

输入：n = 4, k = 9
输出："2314"
示例 3：

输入：n = 3, k = 1
输出："123"
*/
/*
从递归的角度出发，这题与一般的全排列问题的思路是一致的，可以大体套用dfs的模板，但是这样会超时。
那如何在dfs搜索中进行剪枝是本题的关键。回顾下我们使用dfs搜索的过程，下面是dfs搜索树的搜索路径分析。

假设 n = 4, k = 17，我们可以知道第17个全排列为[3,4,1,2]，为了找到它，我们需要在关键节点做剪枝。如何判断呢？
对于n = 4, k=17，全排列的规律：
  第一个数字选1 + 对2,3,4的全排列 (3!个)         3, 1 + 对2,4的全排列(2!个)
  第一个数字选2 + 对1,3,4的全排列 (3!个)         3, 2 + 对1,4的全排列(2!个)
  第一个数字选3 + 对1,2,4的全排列 (3!个)-------> 3, 4 + 对1,2的全排列(2!个)-------> 3, 2, 4 + 对1的全排列(1!个) -------> 3421
  第一个数字选4 + 对1,2,3的全排列 (3!个)         
        
如图，当我们开始搜索时，我们访问紫色节点“1”，注意到此时如果我们继续往下访问（深度搜索），其实是没有意义的，
因为从该节点往下最多有3!=6个全排列组合，而我们要找的是第17个，6<17，所以直接剪枝；
访问紫色节点“2”，同理可知，在该节点处需要剪枝，6 < 11(=17-6)；访问紫色节点“3”,此时满足条件，6 > 5(=11-6)，需要往下搜索。
（这里注意，一个简单的计数技巧，就是当某个节点处需要剪枝时，我们需要更新k值，k = k - 该节点对应阶乘数）。
从紫色节点“3”处，向下搜索，直到搜索完[3,4,1,2]，这就是我们要的答案。

著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
链接：https://leetcode-cn.com/problems/permutation-sequence/solution/jian-ji-cppdfsjian-zhi-by-edward_wang/
*/

class Solution {
private:
  vector<bool> selected;
  vector<int> factorial;
  bool flag = true;

  void dfs(int depth, int n, int &k, string &ret, string path) {
    if (depth == n) {
      ret = path;
      flag = false;
      return;
    }
    int temp = factorial[n - depth - 1];
    for (int i = 0; i < n; i++) {
      if (!selected[i] && flag) {
        if (temp < k) {
          k = k - temp;
          continue;
        }
        path.push_back(i + 1 + '0');
        selected[i] = true;
        dfs(depth + 1, n, k, ret, path);
        selected[i] = false;
        path.pop_back();
      }
    }
  }

public:
  string getPermutation(int n, int k) {
    // calculate the factorial
    if (n == 1) { 
      return "1";
    }
    
    factorial.resize(n);
    factorial[0] = 1;
    factorial[1] = 1;
    if (n > 2) {
      for (int i = 2; i < n; i++) {
        factorial[i] = i * factorial[i-1];
      }
    }
    string ret;
    string path;
    selected.resize(n, false);
    dfs(0, n, k, ret, path);
    return ret;
  }
};
