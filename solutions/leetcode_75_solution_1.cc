/*
The solution requires the use of tracking 3 positions, the Low, Mid and High.

We assume that the mid is the "Unknown" area that we must evaluate.

If we encounter a 0, we know that it will be on the low end of the array, and if we encounter a 2, we know it will be on the high end of the array.

To achieve this in one pass without preprocessing (counting), we simply traverse the unknown will generating the low and high ends.

Take this example:

Assume our input is: 1 0 2 2 1 0 (short for simplicity).

Running the algorithm by hand would look something like:

    1 0 2 2 1 0
    ^         ^
    L         H
    M

    Mid != 0 && Mid != 2
    Mid++

    1 0 2 2 1 0
    ^ ^       ^
    L M       H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 1 2 2 1 0
      ^ ^     ^
      L M     H

    Mid == 2
    Swap High and Mid
    High--

    0 1 0 2 1 2
      ^ ^   ^
      L M   H

    Mid == 0
    Swap Low and Mid
    Mid++
    Low++

    0 0 1 2 1 2
        ^ ^ ^
        L M H

    Mid == 2
    Swap High and Mid
    High--

    0 0 1 1 2 2
        ^ ^
        L M
          H

    Mid <= High is our exit case

https://leetcode.com/problems/sort-colors/discuss/26474/Sharing-C%2B%2B-solution-with-Good-Explanation
*/

class Solution {
  public:
  void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
      if (nums[mid] == 0) {
        swap(nums[mid++], nums[low++]);
      } else if (nums[mid] == 1) {
        mid++;
      } else if (nums[mid] == 2) {
        swap(nums[mid], nums[high--]);
      }
    }
  }
};

/* 为什么low与mid交换后，mid加1；但是high与mid交换后，mid不加1：
解释1
left of the mid will only contain values 0 or 1, because 2 is already moved to the end by mid, 
this is happening because we are moving from left to right.
In this case we are unsure of the values to the right of mid, 
so it can be 0 which is brought to mid by swapping mid <-> right, 
so to move that 0 brought to mid by swapping to 
left we shouldn't increase mid such that in the next iteration it will be moved to the left.
解释2
on the left side of mid everything is sorted and right side is not so we can not increment mid when mid==2
*/