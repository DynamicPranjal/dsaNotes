class Solution {
public:
    
    int n;
    int dp[305][305];
    
    int func(vector<int>& A, int i, int j){
        if(i>j)
            return 0;
        
        if(i==j){
            int x=A[i];
            if(i!=0)
                x*=A[i-1];
            if(i!=n-1)
                x*=A[i+1];
            return x;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        for(int k=i;k<=j;k++){
            int temp=A[k];
            
            if(i!=0)
                temp*=A[i-1];
            if(j!=n-1)
                temp*=A[j+1];
            
            if(k!=0)
                temp+=func(A,i,k-1);
            if(k!=n-1)
                temp+=func(A,k+1,j);
            
            ans=max(ans,temp);
        }
        return dp[i][j]=ans;
    }
        
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        
        return func(nums,0,n-1);
    }
};
