 
class Solution {
public:
    void PrintVector(vector<vector<int> >& output)
    {
        for(int i=0; i<output.size();++i)
        {
            for(int j=0; j<output[i].size();++j)
                cout<<output[i][j]<<"|";
            cout<<endl;
        }
    }
    void Insert(int val, vector<int> & temp_output, vector<vector<int> >& output)
    {
        for(int i=0; i<=temp_output.size();++i)
        {
            vector<int> temp;
            temp.insert(temp.end(), temp_output.begin(), temp_output.begin()+i);
            temp.push_back(val);
            if(i<temp_output.size())
                temp.insert(temp.end(), temp_output.begin()+i, temp_output.end());
            output.push_back(temp);
        }
    }
    
   void  Permute(vector<int>& nums, int start, vector<vector<int> >& output)
    {
        if(start >= nums.size() )
            return;
        int prefix=nums[start];
        vector<vector<int> > temp_output;
        Permute(nums, start+1, temp_output);
        if(temp_output.empty())
        {
            vector<int> temp ={prefix};
            output.push_back(temp);
        }
        else{
        for(int i=0; i< temp_output.size();++i)
        {
            Insert(prefix, temp_output[i], output);
        }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > output;
        Permute(nums, 0, output);
        return output;
    }
};

