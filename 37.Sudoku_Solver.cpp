class Solution {
public:
int cords[2];
pair<int, vector<int>> checkValid(
    int x, int y, vector<vector<char>>& board) {

    int NumOfValid = 0;
    vector<int> c;

    for (int n = 1; n <= 9; n++) {
        bool valid = true;
    
        for (int i = 0; i < 9; i++) {
            if (i != y && board[i][x] == '0' + n)
                valid = false;
        }
        for (int j = 0; j < 9; j++) {
            if (j != x && board[y][j] == '0' + n)
                valid = false;
        } 
        int startX = (x / 3) * 3;
        int startY = (y / 3) * 3;

        for (int i = startY; i < startY + 3; i++) {
            for (int j = startX; j < startX + 3; j++) {
                 if ((i != y || j != x) && board[i][j] == '0' + n)
            valid = false;
            }   
        }
        if (valid) {
            NumOfValid++;
            c.push_back(n);
        }
    }

    return {NumOfValid, c};
}

         int NewValid;
         vector<int> candidates;

    void MRV(vector<vector<char>>& board){
         int OldValid=99;
         candidates.clear();

         for (int j=0;j<9;j++){
              for (int i=0;i<9;i++){
                 if (board[i][j]=='.'){
                    auto result = checkValid(j, i, board);
                   


                    if (result.first == 0) {
                    candidates.clear();
                    return;
                }
                    NewValid = result.first;
                   

                    if (NewValid < OldValid) {
                        cords[0] = i;
                        cords[1] = j;
                        OldValid = NewValid;
                        candidates = result.second;
                       
                    }
                     if(NewValid==1)
                    return;
                
                    
                 }}}}
    bool solve(vector<vector<char>>& board) {

    MRV(board);

    
    if (candidates.empty()) {
       
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    return false;
            }
        }

        return true;
    }

    int x = cords[0];
    int y = cords[1];

    vector<int> options = candidates;

    for (int n : options) {

        board[x][y] = '0' + n;

        if (solve(board))
            return true;

        board[x][y] = '.';
    }

    return false;

}
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);
      
        }
    
};
