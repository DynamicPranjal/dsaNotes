bool isValid(int grid[N][N],int row,int col,int x){
       for(int i = 0; i < N; i++){
           if(grid[row][i] == x) return (false);
           if(grid[i][col] == x) return (false);
           if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == x) return (false);
       }
       return (true);
   }
   
   bool SolveSudoku(int grid[N][N])  
   { 
       for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
               if(grid[i][j] == 0){
                   for(int k = 1; k <= 9; k++){
                       if(isValid(grid,i,j,k)){
                           grid[i][j] = k;
                           if(SolveSudoku(grid)) return (true);
                           grid[i][j] = 0;
                       }
                   }
                   return (false);
               }
           }
       }
       return (true);
   }
   
   //Function to print grids of the Sudoku.
   void printGrid (int grid[N][N]) 
   {
       for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
               cout<<grid[i][j]<<" ";
           }
       }
   }
