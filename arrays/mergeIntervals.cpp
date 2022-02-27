class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        vector<vector<int>>ans;
        sort(A.begin(),A.end());
        for(int i=0;i<A.size();i++){
            if(i==0 or ans.back()[1]<A[i][0]){
                ans.push_back(A[i]);
            }
            else{
                ans.back()[1]=max(ans.back()[1],A[i][1]);
            }
        }
        return ans;
    }
};
