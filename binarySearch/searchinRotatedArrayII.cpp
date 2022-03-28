class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(end-start)/2+start;
            
            if(nums[mid]==target)
                return true;
            
            if(nums[start]==nums[mid] and nums[end]==nums[mid]){
                start++;
                end--;
                continue;
            }
            else if(nums[mid]>=nums[start]){
                if(target>=nums[start] and target<nums[mid])
                    end=mid-1;
                else
                    start=mid+1;
            }
            else{
                if(target>nums[mid] and target<=nums[end])
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return false;
    }
};
