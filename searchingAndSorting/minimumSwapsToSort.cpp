class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    
	    vector<pair<int,int>>A;
	    int n=nums.size();
	    for(int i=0;i<n;i++){
	        A.push_back({nums[i],i});
	    }
	    int swaps=0;
	    
	    sort(A.begin(),A.end());
	    for(int i=0;i<n;i++){
	        if(A[i].second==i)
	            continue;
	        else{
	            swaps++;
	            swap(A[i],A[A[i].second]);
	            i--;
	        }
	    }
	    return swaps;
	}
};
