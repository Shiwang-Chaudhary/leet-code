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
        if(c > 0) upLeft = triangle[r][c] + recursion(r-1, c-1, triangle);
        if(c < triangle[r-1].size()) up = triangle[r][c] + recursion(r-1, c, triangle);
        return dp[r][c] = min(upLeft, up);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        //Method 1: Recurison: TC: O()
        // long minans = INT_MAX;
        // for(int i = 0; i < col; i++){
        //     minans = min(minans, recursion(row-1, i, triangle));
        // }
        // return minans;

        vector<vector<long>>dp(row, vector<long>(col, INT_MAX));
        long minans = INT_MAX;
        for(int i = 0; i < col; i++){
            minans = min(minans, memoization(row-1, i, triangle, dp));
        }
        return minans;
    }
};