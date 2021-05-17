/*
40. 最小的k个数
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，
则最小的4个数字是1、2、3、4。

示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]
*/

/*
我们用一个大根堆实时维护数组的前k小值。首先将前k个数插入大根堆中，随后从第 k+1 
个数开始遍历，如果当前遍历到的数比大根堆的堆顶的数要小，就把堆顶的数弹出，
再插入当前遍历到的数。最后将大根堆里的数存入数组返回即可。在下面的代码中，
由于 C++ 语言中的堆（即优先队列）为大根堆，我们可以这么做。而 Python 语言中的堆为小根堆，
因此我们要对数组中所有的数取其相反数，才能使用小根堆维护前k小值。

提示：前K小，用大顶堆；前K大，用小顶堆。

降序队列，大顶堆（默认）
priority_queue <int,vector<int>, less<int>> pq;
升序队列，小顶堆
priority_queue <int,vector<int>, greater<int>> pq;

*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) { // 排除 0 的情况
            return {};
        }
        vector<int> vec(k, 0);
        priority_queue<int> pq;
        // 首先将前k个数插入大根堆中
        for (int i = 0; i < k; ++i) {
            pq.push(arr[i]);
        }
        // 随后从第 k+1 个数开始遍历，如果当前遍历到的数比大根堆的堆顶的数要小，
        // 就把堆顶的数弹出，再插入当前遍历到的数。
        for (int i = k; i < (int)arr.size(); ++i) {
            if (pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = pq.top();
            pq.pop();
        }
        return vec;
    }
};
