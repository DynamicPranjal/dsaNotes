class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=nums.size()-1;
        
        if(nums.size()==1)
            return nums[0];
        
        while(start<=end){
            int mid=(end-start)/2+start;
            if(mid!=0 and nums[mid]<nums[mid-1])
                return nums[mid];
            else if(nums[start]<=nums[mid] and nums[end]<nums[mid])
                start=mid+1;
            else if(nums[start]>nums[mid] and nums[end]>=nums[mid])
                end=mid-1;
            else
                end--;
        }
        return nums[0];
    }
};
