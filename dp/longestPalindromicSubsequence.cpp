//top-down

class Solution {
public:
    
    int func(string &str,int s,int e, vector<vector<int>>&dp){
        if(s>e)
            return 0;
        if(s==e)
            return dp[s][e]=1;
        
        if(dp[s][e]!=-1)
            return dp[s][e];
        
        if(str[s-1]==str[e-1]){
            dp[s][e]=2+func(str,s+1,e-1,dp);
        }
        else
            dp[s][e]=max(func(str,s+1,e,dp),func(str,s,e-1,dp));
        return dp[s][e];
    }
    
    int longestPalindromeSubseq(string str) {
        int n=str.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return func(str,1,n,dp);
    }
};

//bottom-up

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        
        for(int l=1;l<n;l++){
            for(int i=0;i<n-l;i++){
                int j=i+l;
                if(j-i+1==2){
                    if(s[i]==s[j])
                        dp[i][j]=2;
                    else
                        dp[i][j]=1;
                }
                else{
                    if(s[i]==s[j])
                        dp[i][j]=dp[i+1][j-1]+2;
                    else
                        dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
