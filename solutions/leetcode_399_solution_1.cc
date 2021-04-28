#include "headers.h"

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      // parents["A"] = {"B", 2.0} -> A = 2.0 * B
      // parents["B"] = {"C", 3.0} -> B = 3.0 * C
      unordered_map<string, pair<string, double>> parents;
    
      for (int i = 0; i < equations.size(); ++i) {
        const string& A = equations[i][0];  // 被除数
        const string& B = equations[i][1]; // 除数
        const double k = values[i]; // k是商 A / B = k
        // Neighter is in the forrest
        if (!parents.count(A) && !parents.count(B)) { // A,B都不在并查集里
          parents[A] = {B, k}; // A（被除数）的父亲节点设为B
          parents[B] = {B, 1.0}; // 除数的父亲节点是自己
        } else if (!parents.count(A)) { // A不在并查集里，B在
          parents[A] = {B, k}; // A（被除数）的父亲节点设为B
        } else if (!parents.count(B)) { // B不在并查集里，A在
          parents[B] = {A, 1.0 / k}; // B的父亲节点是A, B = A * 1.0 / k 
        } else { // A,B都在并查集里
          auto& rA = find(A, parents); // 找父亲节点
          auto& rB = find(B, parents);   
          // A = rA.second * rA.first
          // B = rB.second * rB.first
          // A = k * B
          // rA.first / rB.first = k / rA.second * rB.second
          parents[rA.first] = {rB.first, k / rA.second * rB.second}; // 合并
        }    
      }
    
      vector<double> ans;
      for (const auto& pair : queries) {
        const string& X = pair[0];
        const string& Y = pair[1];
        if (!parents.count(X) || !parents.count(Y)) {
          // 都不在并查集
          ans.push_back(-1.0);
          continue;
        }
        auto& rX = find(X, parents); // {rX, X / rX}
        auto& rY = find(Y, parents); // {rY, Y / rY}
        if (rX.first != rY.first) // 两个不同的根节点，即两个不同的集合
          ans.push_back(-1.0);
        else // X / Y = (X / rX / (Y / rY))
          ans.push_back(rX.second / rY.second);
      }
      return ans;
    }
private:
  pair<string, double>& find(const string& C, unordered_map<string, pair<string, double>>& parents) {
    // 查找根节点
    if (C != parents[C].first) {
      const auto& p = find(parents[C].first, parents);
      parents[C].first = p.first;
      parents[C].second *= p.second;
    }
    return parents[C];
  }
};