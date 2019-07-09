//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    void backtrack(vector<int>& candidates, vector<int>&state, int target, int start, vector<vector<int>>&output)
    {
       
        if(target<0) return;
        if(target==0)
        {
            output.push_back(state);
            return;
        }

        for(int i=start; i<candidates.size();++i)
        {
            state.push_back(candidates[i]);
            backtrack(candidates,state, target-candidates[i],i, output);
            state.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        if(candidates.empty())
        {
            return output;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> state;
        backtrack(candidates,state, target, 0, output);
        return output;
    }
};

