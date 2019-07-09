//https://leetcode.com/problems/combination-sum-ii/
class Solution {
public:
    void backtrack(vector<int>& candidates, vector<int>&state, int target, int start, vector<vector<int>>& output)
    {
        if(target<0) return;
        if(target==0)
        {
            output.push_back(state);
            return;
        }
        for(int i=start; i<candidates.size();++i)
        {
            if(i>start && candidates[i]==candidates[i-1]) continue; //skip duplicates
            state.push_back(candidates[i]);
            backtrack(candidates, state, target-candidates[i],i+1, output);
            state.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int>> output;
       if(candidates.empty()) return output;
       sort(candidates.begin(), candidates.end());
       vector<int> state;
        backtrack(candidates, state, target, 0, output);
        return output;
    }
};
 

