class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n, 0);

        vector<int> diff(n, 0);
        for (const auto& booking : bookings) {
            int i = booking[0];
            int j = booking[1];
            int booking_seats = booking[2];
            diff[i - 1] += booking_seats;
            if (j < n) {
                diff[j] -= booking_seats;
            }
        }
        seats[0] = diff[0];
        for (int i = 1; i < diff.size(); ++i) {
            seats[i] = diff[i] + seats[i - 1];
        }
        return seats;
    }
};