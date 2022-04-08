class Solution {
public:
    
    bool check(vector<vector<char>>& board, int i, int j, char c){
        int x=i-i%3;
        int y=j-j%3;
        for(int k=0;k<9;k++) if(board[i][k]==c) return false;
        for(int k=0;k<9;k++) if(board[k][j]==c) return false;
        
        for(int l=0;l<3;l++)
            for(int m=0;m<3;m++){
                if(board[x+l][y+m]==c)
                    return false;
            }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int i, int j) {
        if(i==9) return true;
        if(j==9) return solve(board, i+1, 0);
        
        if(board[i][j]!='.')
            return solve(board, i, j+1);
        
        for(char c='1';c<='9';c++){
            if(check(board, i, j, c)){
                board[i][j]=c;
                if(solve(board, i, j+1)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>&board){
        int i=0,j=0;
        solve(board,i,j);
    }
};
