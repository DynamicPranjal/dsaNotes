class Solution {
public:
    
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    
    void bfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        queue<pair<int,int>>q;
        q.push({x,y});
        
        while(!q.empty()){
            auto pt=q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int xx=pt.first+dx[i];
                int yy=pt.second+dy[i];
                if((xx>=0 and yy>=0 and xx<grid.size() and yy<grid[0].size()) and (grid[xx][yy]=='1' and vis[xx][yy]==false)){
                    q.push({xx,yy});
                    vis[xx][yy]=true;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and vis[i][j]==false){
                    ans++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};
