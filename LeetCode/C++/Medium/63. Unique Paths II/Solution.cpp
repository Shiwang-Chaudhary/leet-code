class Solution {
public:

    int recursion(int row, int col, vector<vector<int>>& obstacleGrid){
        if(row < 0 || col < 0) return 0;
        if(obstacleGrid[row][col] == 1) return 0; //means obstacle found
        if(row == 0 && col == 0) return 1;
        
        int left = recursion(row, col - 1, obstacleGrid);
        int top = recursion(row - 1, col, obstacleGrid);
        
        return left + top;
    }

    int memoization(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(row < 0 || col < 0) return 0;
        if(obstacleGrid[row][col] == 1) return 0; //means obstacle found
        if(row == 0 && col == 0) return 1;
        if(dp[row][col] != 0) return dp[row][col];

        int left = memoization(row, col - 1, obstacleGrid, dp);
        int top = memoization(row - 1, col, obstacleGrid, dp);

        return dp[row][col] = left + top;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        //Method 1: Recursion: TC: O(2^(row+col)) and SC: O(m)
        // //we must send rowindex and colindex instead of number of rows and cols
        // return recursion(row - 1, col - 1, obstacleGrid);

        vector<vector<int>>dp(row, vector<int>(col, 0));
        return memoization(row-1, col-1, obstacleGrid, dp);
    }
};