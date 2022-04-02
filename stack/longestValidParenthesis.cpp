class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n=s.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            else{
                if(st.empty()){
                    st.push(i);
                    continue;
                }
                if(s[st.top()]=='('){
                    // int x=st.top();
                    st.pop();
                    if(st.empty()){
                        ans=max(ans,i+1);
                    }
                    else{
                        ans=max(ans,i-st.top());
                    }
                }
                else{
                    st.push(i);   
                }
            }
        }
        return ans;
    }
};
