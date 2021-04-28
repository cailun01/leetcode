class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0;
        int valid = 0;
        unordered_map<char, int> need, window;
        vector<int> res;
        for (auto c : p) {
            need[c]++;
        }
        
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c) > 0) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    res.push_back(left);
                }
                char d = s[left];
                left++;
                if (need.count(d) > 0) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return res;
    }
};