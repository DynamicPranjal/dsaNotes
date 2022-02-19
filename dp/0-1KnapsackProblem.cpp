class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int dp[1005][1005];
    
    int func(int i,int W,int wt[],int val[]){
        if(i==0 or W==0)
            return 0;
        if(dp[i][W]!=-1)
            return dp[i][W];
        if(wt[i-1]>W){
            return dp[i][W]=func(i-1,W,wt,val);
        }
        else
            return dp[i][W]=max(func(i-1,W-wt[i-1],wt,val)+val[i-1],func(i-1,W,wt,val));
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof(dp));
       int ans=func(n,W,wt,val);
       return ans;
    }
};
