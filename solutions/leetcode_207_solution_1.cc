#include "headers.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degrees(numCourses);//记录所有顶点的入度,未初始化的为0
        vector<vector<int>> adjacents(numCourses); //邻接表
        queue<int> zero;//保存零入度的顶点
        int num = 0;
        for(int i=0;i<prerequisites.size();i++)
        {
            degrees[prerequisites[i][0]]++;//入顶点
            adjacents[prerequisites[i][1]].push_back(prerequisites[i][0]);//出顶点
        }
        for(int i=0;i<numCourses;i++)
            if(degrees[i]==0){
                zero.push(i); //入度为0的先入队列
                num++;
            }
                
        while(!zero.empty()) {
            int temp = zero.front();
            zero.pop();
            for(int j=0;j<adjacents[temp].size();j++) {
              int post = adjacents[temp][j]; // post是temp的后继
              degrees[post] -= 1;
              if(degrees[post] == 0) { // 如果后继节点的入度是0
                zero.push(post);
                num++;
              }
            }     
        }

        return num == numCourses;
    }
};