/* 95. 不同的二叉搜索树 II
给你一个整数n，请你生成并返回所有由n个节点组成且节点值从1到n互不相同的不同二叉搜索树。
可以按任意顺序返回答案。


示例 1：
输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

示例 2：
输入：n = 1
输出：[[1]]
*/

/*
先从简单的看起：根据[1, n]序列构造任意一个二叉搜索树
  可以在[1, n]序列中选任意一个数m为根，则以[1, m-1]为左子树，[m+1, n]为右子树，即可保证二叉搜索树的性质
  可以发现，左右子树也可以 根据[序列] 构造 [二叉搜索树]，那么 递归 二字就呼之欲出了
  设定递归边界：序列区间不可用，即左区间大于右区间
知道了如何构造一个二叉搜索树，那如何将所有的情况都构造一遍呢？
  在上面的例子中， 任意数 m 只需要满足 m ∈ [1, n] 即可，那么可以尝试 遍历
    对[1, n] 遍历，每一个值都可以构造二叉搜索树，其子树也可以递归构造之
  遍历时，保存每个值所能构造的所有可能的情况
  想象一下，你知道了左子树、右子树的所有可能，那么二者相乘即为此树的所有可能！
  将此树的所有可能，作为父节点的一棵子树，递归计算出所有节点的所有可能即可

https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/jian-dan-si-lu-cdi-gui-by-doctor_arknigh-2mjv/
*/

class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    return generate(1, n);
  }

  vector<TreeNode*> generate(int low, int high) {
    if (low > high) {
      // 表示只有一种可能：空树
      return vector<TreeNode*>{nullptr};   
    }
    vector<TreeNode*> res;
    for (int mid = low; mid <= high; ++mid) {
      // 左子树的所有可能
      auto lt = generate(low,  mid - 1);
      // 右子树的所有可能
      auto rt = generate(mid + 1, high);
      for (auto& left : lt) {
        for (auto& right : rt) {
          // 左子树的所有情况 * 右子树的所有情况，即为此树的所有情况
          res.push_back(new TreeNode(mid, left, right));
        }
      }
    }
    return res;
  }
};

