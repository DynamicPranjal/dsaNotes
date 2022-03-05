class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>s;
        int n=h.size();
        int ans=0;
        int temp;
        int i=0;
        
        while(i<n){
            if(s.empty() or h[s.top()]<=h[i]){
                s.push(i);
                i++;
            }
            else{
                int t=s.top();
                s.pop();
                
                temp=h[t] * (s.empty() ? i : i-s.top()-1);
                ans=max(ans,temp);
            }
        }
        
        while(!s.empty()){
            int t=s.top();
            s.pop();
            temp=h[t] * (s.empty() ? i : i-s.top()-1);
            ans=max(ans,temp);
        }
        return ans;
    }
};
