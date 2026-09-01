class Solution {
public:

    bool recHelper(int row, int col, int index, string& word, vector<vector<char>>& board){
        //index represent the index of word
        if(index == word.size()) return true;
        //trow represent totalRows and tcol represent total column, for 1st example,tc = 4, tr=3
        int trow = board.size();
        int tcol = board[0].size();
        char temp = board[row][col];
        //so that we wont use the same element again, use chatgpt for example...
        board[row][col] = '#';
        bool ans = false;
        //Above element
        if(row - 1 >= 0 && board[row-1][col] == word[index]){
            if(recHelper(row - 1, col, index + 1, word, board)){
                //turning back the marked element to its actual value
                board[row][col] = temp;
                return true;
            }
        }
        //Below element
        if(row + 1 < trow && board[row+1][col] == word[index]){
            if(recHelper(row + 1, col, index + 1, word, board)){
                board[row][col] = temp;
                return true;
            }
        }
        //Left element
        if(col - 1 >= 0 && board[row][col-1] == word[index]){
            if(recHelper(row, col - 1, index + 1, word, board)){
                board[row][col] = temp;
                return true;
            }
        }
        //Right element
        if(col + 1 < tcol && board[row][col+1] == word[index]){
            if(recHelper(row, col + 1, index + 1, word, board)){
                board[row][col] = temp;
                return true;
            }
        }
        board[row][col] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(word[0] == board[i][j]){
                    if(recHelper(i, j, 1, word, board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};