//https://leetcode.com/problems/permutations/
class Solution {
public:
    void backtrack(vector<vector<int>>& output, vector<int>& input, vector<int>& temp, unordered_set<int>& visited)
    {
       // cout<<temp.size()<<"\t"<<visited.size()<<endl;
        if(temp.size()==input.size())
        {
            output.push_back(temp);
            return;
        }
      
        for(int i=0; i<input.size();++i)
        {
            if(visited.find(input[i]) != visited.end()) continue;

            temp.push_back(input[i]);
          //  cout<<input[i]<<endl;
            visited.insert(input[i]);

            backtrack(output,input, temp,visited);

            visited.erase(visited.find(input[i]));
            temp.pop_back();

        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> output;
        if(nums.empty())
            return output;
        
        vector<int>temp;
        unordered_set<int> visited;
        backtrack(output, nums, temp, visited);
        return output;
    }
};

