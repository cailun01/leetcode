class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> track;
    sort(candidates.begin(), candidates.end());
    int sum = 0;
    backtrack(track, candidates, target, sum, 0);
    return result;
  }
  
  void backtrack(vector<int>& track, vector<int>& candidates, 
                  int target, int& sum, int start) {
    if (sum == target) {
      result.push_back(track);
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      sum += candidates[i];
      if (sum > target) {
        sum -= candidates[i];
        break;
      }
      track.push_back(candidates[i]);
      backtrack(track, candidates, target, sum, i);
      track.pop_back();
      sum -= candidates[i];
    }
  }
  vector<vector<int>> result;
};


