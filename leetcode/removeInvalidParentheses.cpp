class Solution {
public:
    void func(string s,vector<string> &ans,unordered_map<string,bool> &m,int rem){
        if(m[s])
            return ;
        
        m[s]=true;
        
        if(rem==0){
            int removals_needed=find_rem(s);
            if(removals_needed==0){
                ans.push_back(s);
            }
            return ;
        }
        
        
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            string str=left+right;
            func(str,ans,m,rem-1);
        }
    }
    
    int find_rem(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push('(');
            else if(s[i]==')'){
                if(st.size()!=0 and st.top()=='(') 
                    st.pop();
                else st.push(')');
            }
        }
        return st.size();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        
        unordered_map<string,bool>m;
        int min_rem=find_rem(s);
        vector<string>ans;
        func(s,ans,m,min_rem);
        return ans;
    }
};
