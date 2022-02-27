//O(n^2)
  
class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int n=A.size();
        if(n==1){
            return 1;
        }
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(A[i]>A[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
}; 

//O(nlog(n))

class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        vector<int>ans;
        int n=A.size();
        for(int i=0;i<n;i++){
            auto x=lower_bound(ans.begin(),ans.end(),A[i]);
            if(x==ans.end())
                ans.push_back(A[i]);
            else
                *x=A[i];
        }
        return ans.size();
    }
};
