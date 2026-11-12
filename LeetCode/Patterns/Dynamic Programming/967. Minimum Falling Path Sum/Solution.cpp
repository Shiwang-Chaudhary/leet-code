class Solution {
public:

    long recursion(int row, int col, vector<vector<int>>& matrix){
        if(row < 0 || col < 0 || col >= matrix[0].size()) return INT_MAX;
        if(row == 0) return matrix[0][col];

        long upLeft = matrix[row][col] + recursion(row-1, col-1, matrix);
        long up = matrix[row][col] + recursion(row-1, col, matrix);
        long upRight = matrix[row][col] + recursion(row-1, col+1, matrix);
        return min(upLeft, min(up, upRight));
    }

    long memoization(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(row < 0 || col < 0 || col >= matrix[0].size()) return INT_MAX;
        if(row == 0) return matrix[0][col];
        if(dp[row][col] != INT_MAX) return dp[row][col];

        long upLeft = matrix[row][col] + memoization(row-1, col-1, matrix, dp);
        long up = matrix[row][col] + memoization(row-1, col, matrix, dp);
        long upRight = matrix[row][col] + memoization(row-1, col+1, matrix, dp);

        return dp[row][col] = min(upLeft, min(up, upRight));
    }

    long tabulation(vector<vector<int>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<long>>dp(row, vector<long>(col, INT_MAX));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0){
                    dp[0][j] = matrix[0][j];
                    continue;
                }
                long up = INT_MAX;
                long upLeft = INT_MAX;
                long upRight = INT_MAX;
                if(i > 0){
                    up = matrix[i][j] + dp[i-1][j];
                    if(j > 0){
                        upLeft = matrix[i][j] + dp[i-1][j-1];
                    }
                    if(j < col-1){
                        upRight = matrix[i][j] + dp[i-1][j+1];
                    }
                }
                dp[i][j] = min(upLeft, min(up, upRight));
            }
        }
        long minans = INT_MAX;
        for(int i = 0; i < col; i++){
            minans = min(minans, dp[row-1][i]);
        }
        return minans;
    }

    long optimization(vector<vector<int>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();
        vector<long> prev(col, INT_MAX);
        for(int i = 0; i < row; i++){
            vector<long>curr(col, INT_MAX);
            for(int j = 0; j < col; j++){
                if(i == 0){
                    curr[j] = matrix[0][j];
                    continue;
                }
                int up = INT_MAX;
                int upLeft = INT_MAX;
                int upRight = INT_MAX;
                if(i > 0){
                    up = matrix[i][j] + prev[j];
                    if(j > 0) upLeft = matrix[i][j] + prev[j-1];
                    if(j < col-1) upRight = matrix[i][j] + prev[j+1];
                    curr[j] = min(up, min(upLeft, upRight));
                }
            }
            prev = curr;
        }
        //we have to find the minimum sum from the last row's elements
        long minans = INT_MAX;
        for(int i = 0; i < prev.size(); i++){
            minans = min(minans, prev[i]);
        }
        return minans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        //Method 1: Recursion: TC: O(n x 3^n) and SC: O(n)[recursion stack]
        // //we are sending row and col index instead of actual number of rows and columns
        // long ans = INT_MAX;
        // for(int i = 0; i < col; i++){
        //     long val = recursion(row - 1, i, matrix);
        //     ans = min(ans, val);
        // }
        // return ans;

        //Method 2: Memoization: TC: O(n^2) and SC: O(n^2)[Dp array] + O(n)[recursionstack]
        // long ans = INT_MAX;
        // vector<vector<int>>dp(row, vector<int>(col, INT_MAX));
        // for(int i = 0; i < col; i++){
        //     long val = memoization(row - 1, i, matrix, dp);
        //     ans = min(ans, val);
        // }
        // return ans;

        //Method 3: Tabulation: TC: O(n^2) and SC: O(n^2)[Dp array]
        // return tabulation(matrix);

        return optimization(matrix);
    }
};