class Solution {
public:

    long recursion(int r, int c, vector<vector<int>>& triangle){
        if(r == 0) return triangle[0][0];
        long up = INT_MAX;
        long upLeft = INT_MAX;
        if(c > 0) upLeft = triangle[r][c] + recursion(r-1, c-1, triangle);
        if(c < triangle[r-1].size()) up = triangle[r][c] + recursion(r-1, c, triangle);
        return min(upLeft, up);
    }

    long memoization(int r, int c, vector<vector<int>>& triangle, vector<vector<long>>& dp){
        if(r == 0) return triangle[0][0];
        if(dp[r][c] != INT_MAX) return dp[r][c];
        int up = INT_MAX;
        int upLeft = INT_MAX;
        if(c > 0) upLeft = triangle[r][c] + memoization(r-1, c-1, triangle, dp);
        if(c < triangle[r-1].size()) up = triangle[r][c] + memoization(r-1, c, triangle, dp);
        return dp[r][c] = min(upLeft, up);
    }

    long tabulation(vector<vector<int>>& triangle){
        int row = triangle.size();
        int col = triangle[row-1].size();
        vector<vector<long>>dp(row, vector<long>(col, INT_MAX));
        for(int i = 0; i < row; i++){
            int rcol = triangle[i].size();
            for(int j = 0; j < rcol; j++){
                if(i == 0){
                    dp[0][0] = triangle[0][0];
                    continue;
                }
                long up = INT_MAX;
                long upLeft = INT_MAX;
                if(j > 0) upLeft = triangle[i][j] + dp[i-1][j-1];
                if(j < triangle[i-1].size()) up = triangle[i][j] + dp[i-1][j];
                dp[i][j] = min(upLeft, up);
            }
        }
        long minans = INT_MAX;
        for(int i = 0; i < col; i++){
            minans = min(minans, dp[row-1][i]);
        }
        return minans;
    }

    long optimization(vector<vector<int>>& triangle){
        int row = triangle.size();
        int col = triangle[row-1].size();
        vector<long>prev(col, INT_MAX);
        for(int i = 0; i < row; i++){
            int rcol = triangle[i].size();
            vector<long>curr(rcol, INT_MAX);
            for(int j = 0; j < rcol; j++){
                if(i == 0){
                    curr[0] = triangle[0][0];
                    continue;
                }
                int up = INT_MAX;
                int upLeft = INT_MAX;
                if(j > 0) upLeft = triangle[i][j] + prev[j-1];
                if(j < triangle[i-1].size()) up = triangle[i][j] + prev[j];
                curr[j] = min(upLeft, up);
            }
            prev = curr;
        }
        long minans = INT_MAX;
        for(int i = 0; i < prev.size(); i++){
            minans = min(minans, prev[i]);
        }
        return minans;
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();

        // Method 1: Recursion
        // TC: O(2^row)
        // SC: O(row) [Recursion Stack]

        // long minans = INT_MAX;
        // for(int i = 0; i < col; i++){
        //     minans = min(minans, recursion(row-1, i, triangle));
        // }
        // return minans;

        // Method 2: Memoization
        // TC: O(row^2)
        // SC: O(row^2) [DP Array] + O(row) [Recursion Stack]
        // Overall SC: O(row^2)

        // vector<vector<long>>dp(row, vector<long>(col, INT_MAX));
        // long minans = INT_MAX;
        // for(int i = 0; i < col; i++){
        //     minans = min(minans, memoization(row-1, i, triangle, dp));
        // }
        // return minans;

        // Method 3: Tabulation
        // TC: O(row^2)
        // SC: O(row^2) [DP Array]

        // return tabulation(triangle);

        // Method 4: Space Optimization
        // TC: O(row^2)
        // SC: O(row) [Previous Row + Current Row]

        return optimization(triangle);
    }
};