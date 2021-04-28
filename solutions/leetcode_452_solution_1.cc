class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        } else if (points.size() == 1) {
            return 1;
        }

        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        int count = 1;
        int x_end = points[0][1];
        for (const auto point : points) {
            int start = point[0];
            if (start > x_end) {
                ++count;
                x_end = point[1];
            }
        }
        return count;
    }
};