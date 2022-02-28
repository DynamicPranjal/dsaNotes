class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        if(nums[0]==0)
            return false;
        
        int mxreach=nums[0];
        for(int i=0;i<nums.size();i++){
            if(mxreach<i)
                return false;
            mxreach=max(mxreach,i+nums[i]);
        }
        return true;
    }
};
