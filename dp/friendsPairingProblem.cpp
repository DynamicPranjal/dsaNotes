class Solution{
public:
    int dp[105][10005];
    
    int func(int i,int sum,int A[]){
        if(sum==0)
            return 1;
        if(i==0 or sum<0)
            return 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        return dp[i][sum]=(func(i-1,sum-A[i-1],A) or func(i-1,sum,A));
    }
    
    int equalPartition(int n, int A[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
        }
        if(sum%2)
            return 0;
        
        int ans=func(n,sum/2,A);
        return ans;
    }
};
