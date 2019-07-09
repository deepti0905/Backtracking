//https://leetcode.com/problems/combination-sum-iii/
class Solution {
public:
    void backtrack(vector<int>& input, vector<int>&state, int target, int start, int k, vector<vector<int>>& output)
    {
        if(target<0) return;
        if(target==0)
        {
            if(state.size()==k)
            {
                output.push_back(state);
                
            }
            return;
        }
        
        for(int i=start; i<input.size();++i)
        {
            state.push_back(input[i]);
            backtrack(input, state, target-input[i], i+1, k, output);
            state.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> output;
        if(k==0 || target==0)
            return output;
        
     vector<int> nums={1,2,3,4,5,6,7,8,9};   
     vector<int> state;
     backtrack(nums, state, target, 0, k, output);
     return output;   
    }
};
