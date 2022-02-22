class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>>q;
        for(auto x:m){
            if(x.second>(n+1)/2)
                return "";
            q.push({x.second,x.first});
        }
        
        string ans;
        
        while(!q.empty()){
            pair<int,char>a;
            a=q.top();
            q.pop();
            ans+=a.second;
            a.first-=1;
            
            pair<int,char>b;
            if(!q.empty()){
                b=q.top();
                q.pop();
                ans+=b.second;
                b.first-=1;
                if(b.first)
                    q.push(b);
            }
            if(a.first)
                q.push(a);
        }
        return ans;
    }
};
