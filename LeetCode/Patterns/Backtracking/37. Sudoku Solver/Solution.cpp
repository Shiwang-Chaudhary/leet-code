class Solution {
public:

    bool isSafe(int row, int col, int digit, vector<vector<char>>& board){
        //Column checking
        for(int i = 0; i < 9; i++){
            if(board[i][col] == digit){
                return false;
            }
        }
        //Row checking
        for(int j = 0; j < 9; j++){
            if(board[row][j] == digit) return false;
        }
        //3X3 matrix checking:
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        for(int i = startRow; i < startRow + 3; i++){
            for(int j = startCol; j < startCol + 3; j++){
                if(board[i][j] == digit) return false;
            }
        }
        return true;
    }

    bool recHelper(int rindex, vector<vector<char>>& board){
        // if(rindex == board.size()){
        //     return true;
        // }
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char j = '1'; j <= '9'; j++){
                        if(isSafe(row, col, j, board)){
                            board[row][col] = j;
                            if(recHelper(row, board)){
                                return true;
                                //means no need to trye
                            }
                            board[row][col] = '.';
                        }
                    }
                    // '.' has no valid choice from [1,9], which means our
                    // previous choices led to an invalid state, so we backtrack.
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        recHelper(0, board);
    }
};