class Solution {
public:
    
    void func(int i, int cur, vector<int> &A, vector<vector<int>>& ans, int sum, vector<int>& temp){
        if(cur==sum){
            ans.push_back(temp);
            return ;
        }
        if(cur>sum or i>=A.size())
            return ;
        
        temp.push_back(A[i]);
        func(i,cur+A[i],A,ans,sum,temp);
        temp.pop_back();
        func(i+1,cur,A,ans,sum,temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& A, int sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int cur=0;
        func(0,cur,A,ans,sum,temp);
        return ans;
    }
};
