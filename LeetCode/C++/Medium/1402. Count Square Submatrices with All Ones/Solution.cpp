class Solution {
public:

    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        //dp[i][j] represent the number of squares possible where i and j are the bottom right corner of the square
        vector<vector<int>>dp(row, vector<int>(col, INT_MAX));
        //filling same first row as matrix in dp
        for(int r = 0; r < row; r++){
            dp[r][0] = matrix[r][0];
        }
        //filling same first col as matrix in dp
        for(int c = 0; c < col; c++){
            dp[0][c] = matrix[0][c];
        }
        //filling remaining rows and col
        for(int i = 1; i < row; i++){
            int left = 0;
            int topLeft = 0;
            int top = 0;
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 1){
                    left = matrix[i][j] + dp[i][j-1];
                    topLeft = matrix[i][j] + dp[i-1][j-1];
                    top = matrix[i][j] + dp[i-1][j];
                    dp[i][j] = min(left, min(topLeft, top));
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        int totalSqrs = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                totalSqrs += dp[i][j];
            }
        }
        return totalSqrs;
    }
};