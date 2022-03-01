class Solution {
public:

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        t=(long)t;          // taking t as long because difference between numbers can be greater than INT_MAX
        multiset<long> s;   //window
        
        for(int i=0;i<n;i++){
            if(i>k){
                s.erase((long)nums[i-k-1]); // if size of window > k, we are removing elements from window
            }
            
            auto it=s.lower_bound((long)nums[i]-t); // searching for numbers with difference at most t
            
            long dif=*it-(long)nums[i];    // difference is calculated for further comparisons
            
            if(it!=s.end() and dif<=t){ // if number in window with at most t difference is present 
                return true;
            }
            s.insert(nums[i]); // inserting element in window 
        }
        return false;
    }
	// Thanks
};
