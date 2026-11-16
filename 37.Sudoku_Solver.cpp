class Solution {
public:
 bool isValid(int x, int y, char n,vector<vector<char>>& board) { //Check if number is valid (is not in column,row or square) return false if not valid
  for (int i = 0; i < 9; i++) {
    if (i != y && board[i][x] == n)
        return false;
} 

  for (int j = 0; j < 9; j++) {
    if (j != x && board[y][j] == n)
        return false;
} 
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;

  for (int i = startY; i < startY + 3; i++) {
        for (int j = startX; j < startX + 3; j++) {
           if (board[i][j] == n && (i != y || j != x))
        return false;
        }
}

    return true;
}
    bool solve(vector<vector<char>>& board){ //Recursion, backtrack if no further number is invalid or the board is not solvable with current number
         for (int j=0;j<9;j++){
              for (int i=0;i<9;i++){
                 if (board[i][j]=='.'){
                     for (char n = '1'; n <= '9'; n++){
                         if(isValid(j,i,n,board)){
                               board[i][j]=n;
                                if (solve(board)){
                                return true;
                               } 
                               else{board[i][j]='.';} 
                         }
                         //else{board[i][j]='.';} <-- Not needed , redundancy 
                     }
                     return false;
                 }
                 
              }
        }return true;
}
    void solveSudoku(vector<vector<char>>& board) {
            solve(board);
        }
        
};
