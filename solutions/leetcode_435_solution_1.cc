class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });

        int count = 0;
        int x_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            const vector<int>& interval = intervals[i];
            int start = interval[0];
            if (start >= x_end) {
                x_end = interval[1];
            } else {
                ++count;
            }
        }
        return count;
    }
};