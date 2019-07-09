//https://leetcode.com/problems/subsets
class Solution {
public:
    void subsetLocal(int index, vector<int>& nums, vector<int>& state, vector<vector<int> >& output)
    {
        if(index > nums.size()) return;
        if(index==nums.size())
        {
            vector<int> temp;
            for(int i=0; i<nums.size();++i)
            {
                if(state[i] >0)
                    temp.push_back(nums[i]);
            }
            output.push_back(temp);
            return;
        }
        
        subsetLocal(index+1, nums, state, output);
        state[index]=1;
        subsetLocal(index+1, nums, state, output);
        state[index]=0;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int>state(nums.size(),0);
        subsetLocal(0, nums,state, output);
        return output;
    }
};

