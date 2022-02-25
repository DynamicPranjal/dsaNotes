class Solution {
public:
    vector<string> ans;
    unordered_map<string,bool> m;
    
    void func(int i, string s, string v){
        if(i==s.size()){
            v.pop_back();
            ans.push_back(v);
            return ;
        }
        
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(m.find(temp)!=m.end()){
                string str=v+temp+" ";
                func(j+1,s,str);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto x:wordDict){
            m[x]=1;
        }
        string v;
        func(0,s,v);
        return ans;
    }
};
