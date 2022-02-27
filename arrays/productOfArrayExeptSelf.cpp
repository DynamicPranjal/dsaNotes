class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int beg=1;
        int end=1;
        int n=nums.size();
        vector<int>ans(n,1);
        
        for(int i=0;i<n;i++){
            ans[i]*=beg;
            beg*=nums[i];
            ans[n-i-1]*=end;
            end*=nums[n-i-1];
        }
        
        return ans;
    }
};
