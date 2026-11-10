class Solution {
public:

    int recursion(int rowIndex, int colIndex){
        if(rowIndex < 0) return 0;
        if(colIndex < 0) return 0;
        if(colIndex == 0 && rowIndex == 0) return 1;
        // going left
        int left = recursion(rowIndex, colIndex - 1);
        // going top
        int top = recursion(rowIndex - 1, colIndex);
        return left + top;
    }

    int memoization(int rowIndex, int colIndex, vector<vector<int>>& dp){
        if(rowIndex < 0) return 0;
        if(colIndex < 0) return 0;
        if(colIndex == 0 && rowIndex == 0) return 1;
        if(dp[rowIndex][colIndex] != -1) return dp[rowIndex][colIndex];
        // going left
        int left = memoization(rowIndex, colIndex - 1, dp);
        // going top
        int top = memoization(rowIndex - 1, colIndex, dp);
        return dp[rowIndex][colIndex] = left + top;
    }

    //Taking path from m-1, n-1 to 0,0 basically doing the opposite and we can only move either left or top
    int uniquePaths(int m, int n) {
        //Method 1: Recursion:
        // return recursion(m-1, n-1);

        //Method 2: Memoization:
        //2D dp
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memoization(m-1, n-1, dp);
    }
};