class Solution {
public:
    
    int func(int i, int j, string s, string p, vector<vector<int>>&dp){
        if(j==p.size())
            return i==s.size();
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        int flag=0;
        if(i<s.size() and (s[i]==p[j] or p[j]=='.'))
            flag=1;
        
        if(j<p.size()-1 and p[j+1]=='*')
            ans=func(i,j+2,s,p,dp) or (flag and func(i+1,j,s,p,dp));
        else 
            ans=flag and func(i+1,j+1,s,p,dp);
        return dp[i][j]=ans;
    }
    
    bool isMatch(string s, string p) {
        int i=0,j=0;
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        int ans=func(i,j,s,p,dp);
        return ans;
    }
    
};
