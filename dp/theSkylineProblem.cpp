class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int>A;
        for(auto x:buildings){
            A.push_back(x[0]);
            A.push_back(x[1]);
        }
        
        sort(A.begin(),A.end());
        int m=unique(A.begin(),A.end())-A.begin();
        
        priority_queue<pair<int,int>>q;
        
        int j=0;
        int prev=0,cur=0;
        vector<vector<int>>ret;
        
        for(int i=0;i<m;i++){
            while(j<buildings.size() and A[i]>=buildings[j][0])
                q.push({buildings[j][2],buildings[j][1]}),j++;
            while(!q.empty() and q.top().second<=A[i])
                q.pop();
            
            int cur=q.empty()? 0: q.top().first;
            if(cur!=prev){
                ret.push_back({A[i],cur});
                prev=cur;
            }
        }
        return ret;
    }
};
