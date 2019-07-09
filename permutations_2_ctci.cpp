 
class Solution {
    unordered_map<int,int> hash;
    int size;
public:
    
    void RecursiveFunc(int index, vector<int>& state, vector<vector<int>>& output)
    {
        if(index > size)
            return;
        if(index == size)
        {
            output.push_back(state);
            return;
        }
        
        for(unordered_map<int,int>::iterator iter= hash.begin(); iter!= hash.end();++iter)
        {
            if(iter->second <= 0)
                continue;
            
            state[index]=iter->first;
            iter->second--;
            RecursiveFunc(index+1, state, output);
            iter->second++;
            
            
        }
            
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    
        if(nums.empty())
        return vector<vector<int>>();
        size=nums.size();
        
        for(int i=0; i<nums.size();++i)
            hash[nums[i]]++;
        
        vector<int> state(nums.size(),0);
         vector<vector<int>> output;
        RecursiveFunc(0, state, output);
        return output;
        
    }
    
};
 

