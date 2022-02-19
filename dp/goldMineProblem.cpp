Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons.
Initially the miner can start from any row in the first column. From a given cell, the miner can move

to the cell diagonally up towards the right 
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.
  

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> A)
    {
        // code here
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int r,rd,ru;
                r=A[i][j]+A[i][j-1];
                if(i+1==n)
                    ru=0;
                else
                    ru=A[i][j]+A[i+1][j-1];
                if(i-1<0)
                    rd=0;
                else 
                    rd=A[i][j]+A[i-1][j-1];
                A[i][j]=max({r,ru,rd});
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,A[i][m-1]);
        }
        return ans;
    }
};
