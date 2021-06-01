题解：https://leetcode-cn.com/problems/valid-sudoku/solution/you-xiao-de-shu-du-by-leetcode/
一个简单的解决方案是遍历该 9 x 9 数独 三 次，以确保：

行中没有重复的数字。
列中没有重复的数字。
3 x 3 子数独内没有重复的数字。
实际上，所有这一切都可以在一次迭代中完成。

方法：一次迭代
首先，让我们来讨论下面两个问题：

如何枚举子数独？
可以使用 box_index = (row / 3) * 3 + columns / 3，其中 / 是整数除法。
