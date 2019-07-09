//https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    void backtrack(vector<vector<int>>& output, vector<int>& input, vector<int>& temp, vector<bool>& used)
    {
        //cout<<temp.size()<<"\t"<<input.size()<<endl;
        if(temp.size()==input.size())
        {
            output.push_back(temp);
            return;
        }
      
        for(int i=0; i<input.size();++i)
        {
           if(used[i] || i> 0 && input[i]==input[i-1] && !used[i-1]) continue;
            used[i]=true;           
            temp.push_back(input[i]);
             backtrack(output,input, temp,used);
             temp.pop_back();
            used[i]=false;
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        if(nums.empty())
            return output;
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<bool> used(nums.size(), false);
        backtrack(output, nums, temp, used);
        return output;
    }
};

