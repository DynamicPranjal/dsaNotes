class Solution{
public:

    vector<vector<int>>ans;
    vector<int>v;

    bool valid(int r,int c,int n,vector<vector<char>> &board){
        int i=r,j=c;
        
        while(i>=0 and j>=0){
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        
        j=c;
        while(j>=0){
            if(board[r][j]=='Q')
                return false;
            j--;
        }
        
        i=r,j=c;
        while(i<n and j>=0){
            if(board[i][j]=='Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void func(int c,int n,vector<vector<char>> & board){
        if(c==n){
            ans.push_back(v);
            return ;
        }
        
        for(int r=0;r<n;r++){
            if(valid(r,c,n,board)){
                v.push_back(r+1);
                board[r][c]='Q';
                func(c+1,n,board);
                board[r][c]='.';
                v.pop_back();
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<char>>board(n,vector<char>(n,'.'));
        func(0,n,board);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
