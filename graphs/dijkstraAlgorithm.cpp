class Solution
{
	  public:
	  //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > >q;
        vector<int> d(n,1e9);
        q.push({S,0});
        d[S]=0;
        
        while(!q.empty()){
            int cur=q.top().first;
            int cur_d=q.top().second;
            q.pop();
            
            for(auto x:adj[cur]){
                if(cur_d+x[1]<d[x[0]]){
                    d[x[0]]=cur_d+x[1];
                    q.push({x[0],d[x[0]]});
                }
            }
        }
        return d;
    }
};
