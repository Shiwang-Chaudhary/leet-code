class Solution {
public:
    bool isSafe(int row, int col, int n, vector<vector<char>>& board){
        int dummyRow = row;
        int dummyCol = col;
        //Checking if Q is already placed in same column (UPPER CASE):
        while(dummyRow >= 0){
            if(board[dummyRow][dummyCol] == 'Q'){
                return false;
            }
            dummyRow--;
        }
        dummyRow = row;
        dummyCol = col;
        //Checking if Q is already placed in upper left diagonal (UPPER LEFT DIAGONAL CASE):
        while(dummyRow >= 0 && dummyCol >= 0){
            if(board[dummyRow][dummyCol] == 'Q') return false;
            dummyRow--;
            dummyCol--;
        }
        dummyRow = row;
        dummyCol = col;
        //Checking if Q is already placed in upper right diagonal (UPPER RIGHT DIAGONAL CASE):
        while(dummyRow >= 0 && dummyCol < n){
            if(board[dummyRow][dummyCol] == 'Q') return false;
            dummyRow--;
            dummyCol++;
        }
        //There is no need to check for lower because we are inserting Q from top so there is no queen in the bottom...
        return true;
    }
    void backtrack(int row, int n, vector<string>& temp, vector<vector<char>>& board, vector<vector<string>>& ans){
        if(row == n){
            ans.push_back(temp);
            return;
        }
        for(int col = 0; col < n; col++){
            string s(n, '.');
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                s[col] = 'Q';
                temp.push_back(s);
                backtrack(row + 1, n, temp, board, ans);
                board[row][col] = '.';
                temp.pop_back();
            }
        }
    }
    //This is not the optimal solution but chatgpt says its enough for interview
    //Optima solution TC: O(n!) and SC: O(s * n^2) where s is number of valid N queen solutions
    vector<vector<string>> solveNQueens(int n) {
        //Less optimal solurion: TC: O(N*N!) and SC: O(N^2)... but good for interview
        vector<vector<char>> board(n, vector<char>(n,'.'));
        vector<string> temp;
        vector<vector<string>> ans;
        backtrack(0, n, temp, board, ans);
        return ans;
    }
};