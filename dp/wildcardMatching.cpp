class Solution {
public:
    
    bool func(int i, int j, string &s, string &p, vector<vector<int>>&dp){
        if(j==p.size())
            return i==s.size();
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        bool flag=0;
        bool ans=0;
        
        if(i==s.size() and p[j]=='*')
            ans=func(i,j+1,s,p,dp);
        
        else if(p[j]=='*')
            ans=(func(i,j+1,s,p,dp) or func(i+1,j,s,p,dp));
        
        else{
            flag=(i<s.size() and (s[i]==p[j] or p[j]=='?'));
            ans=(flag and func(i+1,j+1,s,p,dp));
        }
        
        dp[i][j]=ans?1:0;
        return ans;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        int i=0,j=0;
        return func(i,j,s,p,dp);
    }
};
