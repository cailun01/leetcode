/*
给定一个包含 [0，n) 中不重复整数的黑名单 blacklist ，写一个函数从 [0, n) 中返回一个不在 blacklist 中的随机整数。

对它进行优化使其尽量少调用系统方法 Math.random() 。

提示:

1 <= n <= 1000000000
0 <= blacklist.length < min(100000, N)
[0, n) 不包含 n ，详细参见 interval notation 。
示例 1：

输入：
["Solution","pick","pick","pick"]
[[1,[]],[],[],[]]
输出：[null,0,0,0]

示例 2：
输入：
["Solution","pick","pick","pick"]
[[2,[]],[],[],[]]
输出：[null,1,1,1]

示例 3：
输入：
["Solution","pick","pick","pick"]
[[3,[1]],[],[],[]]
输出：[null,0,0,2]

示例 4：
输入： 
["Solution","pick","pick","pick"]
[[4,[2]],[],[],[]]
输出：[null,1,3,1]

输入语法说明：
输入是两个列表：调用成员函数名和调用的参数。Solution的构造函数有两个参数，
n 和黑名单 blacklist。pick 没有参数，输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。
*/

class Solution {
public:
    int sz;
    unordered_map<int, int> mapping;
    Solution(int N, vector<int>& blacklist) {
        // 最终数组中的元素个数
        sz = N - blacklist.size();
		// 先将所有黑名单数字加入 map
	    for (int b : blacklist) { 
	        // 这里赋值多少都可以
	        // 目的仅仅是把键存进哈希表
	        // 方便快速判断数字是否在黑名单内
	        mapping[b] = 666;
	    }

        // 最后一个元素的索引
        int last = N - 1;
        // 将黑名单中的索引换到最后去
	    for (int b : blacklist) {
            // 如果 b 已经在区间 [sz, N)
            // 可以直接忽略
            if (b >= sz) {
                continue;
            }

	        // 跳过所有黑名单中的数字
	        while (mapping.count(last)) {
	            last--;
	        }
	        // 将黑名单中的索引映射到合法数字
	        mapping[b] = last;
	        last--;
	    }
    }
    
    int pick() {
        // 随机选取一个索引
        int index = rand() % sz;
        // 这个索引命中了黑名单，
        // 需要被映射到其他位置
        if (mapping.count(index)) {
            return mapping[index];
        }
        // 若没命中黑名单，则直接返回
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */