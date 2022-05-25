class Solution {
public:
    
    static bool cmp(const vector<int>&A, const vector<int>&B){
        return (A[0]==B[0])? B[1]<A[1] : A[0]<B[0];
    } 
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n=envelopes.size();
        vector<int>ans;
        
        // for(int i=0;i<n;i++){
        //     cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
        // }
        
        for(int i=0;i<n;i++){
            int x=envelopes[i][1];
            int pos=lower_bound(ans.begin(),ans.end(),x)-ans.begin();
            if(pos==ans.size()) ans.push_back(x);
            ans[pos]=x;
        }
        
        return ans.size();
    }
};
