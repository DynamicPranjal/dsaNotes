class Solution {
public:
    
    void func(vector<vector<int>> &ans, vector<int> &ds, unordered_map<int,int>&m, vector<int>& nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return ;
        }
        
        for(int i=0;i<nums.size();i++){
            if(m[i]==0){
                ds.push_back(nums[i]);
                m[i]=1;
                func(ans,ds,m,nums);
                m[i]=0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        unordered_map<int,int>m;
        func(ans,ds,m,nums);
        return ans;
    }
};

//reduced space

class Solution {
public:
    
    void func(int ind, vector<vector<int>> &ans, vector<int> &nums){
        if(ind==nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            func(ind+1,ans,nums);
            swap(nums[i],nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        func(0,ans,nums);
        return ans;
    }
};
