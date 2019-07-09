/**
THis will exceed time limit
class Solution {
    
public:
    void backtrack(vector<int>& nums, int target, int &output)
    {
        if(target<0) return;
        if(target == 0)
        {
            output++;
            return;
        }
        for(int i=0; i<nums.size();++i)
        {
            backtrack(nums, target-nums[i], output);
        }
    }
    int combinationSum4(vector<int>& nums, int target) {
     if(nums.empty())return 0;
     sort(nums.begin(), nums.end());   
     int output=0;   
     backtrack(nums, target,output);
     return output;   
    }
};
**/
//https://leetcode.com/problems/combination-sum-iv/
class Solution {
    unordered_map<int,int> hash;
public:
    int backtrack(vector<int>& nums, int target)
    {
        if(target<0) return 0;
        if(target==0) return 1;
        if(hash.find(target) != hash.end()) return hash[target];
       
        int res=0;
        for(int i=0; i<nums.size();++i)
        {
            if(target>=nums[i])
                res+=backtrack(nums, target-nums[i]);
        }
        hash[target]=res;
        return hash[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty())return 0;
     sort(nums.begin(), nums.end());   
       
     return backtrack(nums, target);
        
    }
};
