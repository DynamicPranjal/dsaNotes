class Solution {
public:
    
    void func(int i,int cur,vector<vector<int>> &ans, vector<int> &temp, vector<int> &A, int sum){
        if(cur==sum){
            ans.push_back(temp);
            return ;
        }
        if(i>=A.size() or cur>sum)
            return ;

        for(int j=i;j<A.size();j++){
            if(j>i and A[j]==A[j-1])
                continue;
            temp.push_back(A[j]);
            func(j+1,cur+A[j],ans,temp,A,sum);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& A, int sum) {
        vector<vector<int>> ans;
        vector<int>temp;
        int cur=0;
        sort(A.begin(),A.end());
        func(0,cur,ans,temp,A,sum);
        return ans;
    }
};
