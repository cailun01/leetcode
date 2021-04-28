class Solution {
public:
    bool can_finish(int speed, vector<int>& piles, int h) {
        int time = 0;
        for (const auto& pile : piles) {
            time += ((pile - 1) / speed + 1);
            if (time > h) {
                return false;
            }
        }
        return time <= h;
    }

    int get_max_speed(vector<int>& piles) {
        int max_speed = 1;
        for (const auto& pile : piles) {
            max_speed = max(max_speed, pile / 1);
        }
        return max_speed;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int min = 1;
        int max = get_max_speed(piles);
        while (min < max) {
            int mid = (min + max) / 2;
            if(can_finish(mid ,piles,h)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return max;
    }
};