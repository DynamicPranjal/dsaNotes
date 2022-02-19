class Solution
{
public:
    int dp[1105];
    
    int wb(int pos, string A, vector<string> &B, set<string> &st){
        if(pos==A.size())
            return 1;
            
        string temp;
        
        if(dp[pos]!=-1)
            return dp[pos];
        
        for(int i=pos;i<A.size();i++){
            temp+=A[i];
            if(st.find(temp)!=st.end()){
                if(wb(i+1,A,B,st)){
                    return dp[pos]=1;
                }
            }
        }
        return dp[pos]=0;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        memset(dp,-1,sizeof(dp));
        set<string>st;
        for(auto x:B){
            st.insert(x);
        }
        return wb(0,A,B,st);
    }
};
