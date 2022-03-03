class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        for(auto x:tasks)
            m[x]++;
        
        priority_queue<pair<int,char>>q;
        for(auto x:m){
            q.push({x.second,x.first});
        }
        
        int cycle=n+1;
        int ans=0;
        
        while(!q.empty()){
            int time=0;
            vector<pair<int,char>>temp;
            for(int i=0;i<cycle;i++){
                if(!q.empty()){
                    temp.push_back(q.top());
                    q.pop();
                    time++;
                }
            }
            for(auto x:temp){
                if(--x.first)
                    q.push({x.first,x.second});
            }
            ans+= (!q.empty()) ? cycle : time;
        }
        return ans;
    }
};
