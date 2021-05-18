/*
 f(x) 是 x! 末尾是 0 的数量。（回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 ）

例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。
给定 K，找出多少个非负整数 x ，能满足 f(x) = K 。

示例 1：
输入：K = 0
输出：5
解释：0!, 1!, 2!, 3!, and 4! 均符合 K = 0 的条件。

示例 2：
输入：K = 5
输出：0
解释：没有匹配到这样的 x!，符合 K = 5 的条件。

提示：
K是范围在 [0, 10^9] 的整数。
*/

class Solution {
public:
    using int64 = long long;
    int64 trailingZeroes(int64 n) {
        int64 count = 0;
        while (n > 0) {
            count += n / 5;
            n = n / 5;
        }
        return count;
    }
    
    int64 lower_bound(int target) {
        int64 low = 0, high = numeric_limits<int64>::max();
        while (low < high) {
            int64 mid = low + (high - low) / 2;
            if (trailingZeroes(mid) > target) {
                high = mid;
            } else if (trailingZeroes(mid) == target) {
                high = mid;
            } else if (trailingZeroes(mid) < target) {
                low = mid + 1;
            }
        }
        return low;
    }

    int64 upper_bound(int target) {
        int64 low = 0, high = numeric_limits<int64>::max();
        while (low < high) {
            int64 mid = low + (high - low) / 2;
            if (trailingZeroes(mid) > target) {
                high = mid;
            } else if (trailingZeroes(mid) == target) {
                low = mid + 1;
            } else if (trailingZeroes(mid) < target) {
                low = mid + 1;
            }
        }
        return low;
    }

    int preimageSizeFZF(int k) {
        return upper_bound(k) - lower_bound(k);
    }
};