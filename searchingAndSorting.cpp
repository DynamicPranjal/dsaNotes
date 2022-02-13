class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int sum) {
        // Your code goes here
        
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int s=arr[i]+arr[j];
                int left=j+1;
                int right=n-1;
                int t=sum-s;
                
                while(left<right){
                    int le=arr[left];
                    int ri=arr[right];
                    if(arr[left]+arr[right]>t){
                        right--;
                    }
                    else if(arr[left]+arr[right]<t){
                        left++;
                    }
                    else{
                        vector<int>A;
                        A.push_back(arr[i]);
                        A.push_back(arr[j]);
                        A.push_back(le);
                        A.push_back(ri);
                        ans.push_back(A);
                        while(left<right and arr[left]==le)
                            left++;
                        while(left<right and arr[right]==ri)
                            right--;
                    }
                }
                while(j<n+1 and arr[j]==arr[j+1])
                    j++;
            }
            while(i<n+1 and arr[i]==arr[i+1])
                i++;
        }
        return ans;
    }
};
