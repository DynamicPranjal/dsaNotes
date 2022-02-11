class Solution {
public:
    
    void func(vector<vector<int>> &ans,vector<int> &nums,int ind){
        if(ind==nums.size()){
            ans.push_back(nums);
            return ;
        }
        
        unordered_set<int>s;
        for(int i=ind;i<nums.size();i++){
            if(s.find(nums[i])!=s.end()) continue;
            s.insert(nums[i]);
            swap(nums[ind],nums[i]);
            func(ans,nums,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        func(ans,nums,0);
        return ans;
    }
};
