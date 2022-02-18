class Solution{
    public:
    
    vector<string>ans;
    
    void func(int x,int y,vector<vector<int>> &vis,string str,vector<vector<int>> &A,int n){
        if(x>=n or y>=n or x<0 or y<0 or A[x][y]==0 or vis[x][y]==1)
            return ;
        if(x==n-1 and y==n-1){
            ans.push_back(str);
            return ;
        }
        vis[x][y]=1;
        func(x-1,y,vis,str+"U",A,n);
        func(x+1,y,vis,str+"D",A,n);
        func(x,y-1,vis,str+"L",A,n);
        func(x,y+1,vis,str+"R",A,n);
        vis[x][y]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &A, int n) {
        // Your code goes here
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(A[0][0]==0 or A[n-1][n-1]==0)
            return ans;
        string str="";
        func(0,0,vis,str,A,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
