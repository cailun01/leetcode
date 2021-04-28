#include "headers.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // 0号房间无钥匙
        if(rooms[0].empty()){
            // 房间数量为1时，已经进入了有且只有的一个房间
            if(rooms.size() == 1)
                return true;
            return false; // 房间数量多于一个时
        } 
        queue<int> keys;
        vector<int> entered(rooms.size(), 0);
        // 查找该房间是否已经被打开
        unordered_set<int> visited;
        
        keys.push(0);
        
        while(!keys.empty()) {
            int index = keys.front();
            keys.pop();
            visited.insert(index);
            entered[index]++;
            
            for(int i = 0; i < rooms[index].size(); i++) {
                int next = rooms[index][i];
                if(visited.find(next) == visited.end()){
                    keys.push(next);
                }
            }
        }
        
        for(int i = 0; i < entered.size(); i++) {
            if(entered[i] == 0)
                return false;
        }
        return true;
    }
};
