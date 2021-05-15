#include "headers.h"
/* 
插入排序

1.从数组的第2个数据开始往前比较，即一开始用第2个数和他前面的一个比较，如果符合条件
（比前面的大或者小，自定义），则让他们交换位置。

2.然后再用第3个数和第2个比较，符合则交换，但是此处还得继续往前与第1个数比较。
比如有5个数：8，15，20，45, 17。前4个已经有序，17比45小，需要交换，但是17也比20小，也要交换，当不需要和15交换以后，
说明也不需要和15前面的数据比较了，因为前面的数据都是有序的。

3.重复步骤2，一直到数据全都排完。

*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            int j = i;
            int temp = nums[j];
            while (j > 0 && temp < nums[j - 1]) {
                nums[j] = nums[j - 1];
                --j;
            }
            nums[j] = temp;
        }
        return nums;
    }
};