#include "headers.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r = strs.size() ? strs[0] : ""; // 假设strs[0]为公共前缀
        for(auto s: strs){
            while(s.substr(0, r.size()) != r){ // 判断r是否是s的子串
                // 如果不是，删去r的最后一个字符，再进行判断
                r = r.substr(0, r.size() - 1);
                if(r == "") return r;
            }
        }
        return r;
    }
};
