class Solution {
public:
    
    bool isvalid(int i, int j, vector<vector<bool>> &vis, int n, int m){
        if(i>=0 and j>=0 and i<n and j<m and vis[i][j]==0)
            return true;
        return false;
    }
    
    bool flag=0;
        
    void dfs(int i,int j, int s, string temp, vector<vector<char>> &A, string w, vector<vector<bool>> &vis){
        
        if(A[i][j]==w[s]){
            vis[i][j]=1;
            temp+=w[s];
            if(temp.size()==w.size() and temp==w){
                flag=1;
                return ;
            }
            if(isvalid(i+1,j,vis,A.size(),A[0].size())){
                dfs(i+1,j,s+1,temp,A,w,vis);
            }
            if(isvalid(i-1,j,vis,A.size(),A[0].size())){
                dfs(i-1,j,s+1,temp,A,w,vis);
            }
            if(isvalid(i,j-1,vis,A.size(),A[0].size())){
                dfs(i,j-1,s+1,temp,A,w,vis);
            }
            if(isvalid(i,j+1,vis,A.size(),A[0].size())){
                dfs(i,j+1,s+1,temp,A,w,vis);
            }
            vis[i][j]=0;
            temp.pop_back();
        }
    }
    
    bool exist(vector<vector<char>>& A, string w) {
        int n=A.size();
        int m=A[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
            
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==w[0]){
                    vis[i][j]=1;
                    string temp;
                    temp+=w[0];
                    if(temp==w)
                        return true;
                    if(isvalid(i+1,j,vis,n,m)){
                        dfs(i+1,j,1,temp,A,w,vis);
                    }
                    if(isvalid(i-1,j,vis,n,m)){
                        dfs(i-1,j,1,temp,A,w,vis);
                    }
                    if(isvalid(i,j+1,vis,n,m)){
                        dfs(i,j+1,1,temp,A,w,vis);
                    }
                    if(isvalid(i,j-1,vis,n,m)){
                        dfs(i,j-1,1,temp,A,w,vis);
                    }
                    vis[i][j]=0;
                    temp.pop_back();
                }
            }
        }
        if(flag==1)
            return true;
        return false;
    }
};
