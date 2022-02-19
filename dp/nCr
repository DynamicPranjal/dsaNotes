class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(r>n)
        return 0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int k=min(r,n-r);
        for(int i=1;i<=n;i++){
            for(int j=min(i,k);j>0;j--){
                dp[j]=(dp[j-1]+dp[j])%1000000007;
            }
        }
        return dp[k];
    }
};
