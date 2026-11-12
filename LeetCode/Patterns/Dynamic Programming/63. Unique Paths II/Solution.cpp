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

    int tabulation(vector<vector<int>>& obstacleGrid){
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;//if starting index has osbtacle
        vector<vector<int>>dp(row, vector<int>(col, 0));
        dp[0][0] = 1; //if(row==0 && col == 0) return 1 bala case
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 && j == 0) continue;
                if(obstacleGrid[i][j] == 1) continue;
                int left = 0;
                int top = 0;
                if(j > 0) left = dp[i][j-1];
                if(i > 0) top = dp[i-1][j];
                dp[i][j] = left + top;
            }
        }
        return dp[row-1][col-1];
    }

    int optimization(vector<vector<int>>& obstacleGrid){
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0; //if starting index has osbtacle
        vector<int>prev(col, 0);
        for(int i = 0; i < row; i++){
            vector<int>curr(col, 0);
            for(int j = 0; j < col; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }
                int left = 0;
                int top = 0;
                if(obstacleGrid[i][j] == 1) continue;
                if(j > 0) left = curr[j-1];
                if(i > 0) top = prev[j];
                curr[j] = left + top;
            }
            prev = curr;
        }
        return prev[col-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        //Method 1: Recursion: TC: O(2^(row+col)) and SC: O(m)
        // //we must send rowindex and colindex instead of number of rows and cols
        // return recursion(row - 1, col - 1, obstacleGrid);

        //Method 2: Memoization: TC: O(m x n) and SC: O(m) + O(mxn)
        // vector<vector<int>>dp(row, vector<int>(col, 0));
        // //we must send rowindex and colindex instead of number of rows and cols
        // return memoization(row-1, col-1, obstacleGrid, dp);

        //Method 3: Tabulation: TC: O(m x n) and SC: O(mxn)
        // return tabulation(obstacleGrid);

        return optimization(obstacleGrid);
    }
};