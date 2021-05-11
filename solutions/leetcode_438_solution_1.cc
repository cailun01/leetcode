class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0;
        // valid变量表示窗口中满足need条件的字符个数
        int valid = 0;
        // need记录p中的字符出现的次数
        // window记录窗口中的字符出现的次数
        unordered_map<char, int> need, window;
        vector<int> res;
        for (auto c : p) {
            need[c]++;
        }
        
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.find(c) != need.end()) {
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
                if (need.find(d) != need.end()) {
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