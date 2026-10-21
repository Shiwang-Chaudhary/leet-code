class Solution {
public:

    int solve2(int n, vector<int>& dp){
        if(n <= 2) return n;
        //base case:
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    //Approach1: Memoization approach: TC: O(n) and SC: O(n)[recursion stack]
    int solve1(int n, vector<int>& dp){
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = solve1(n-1, dp) + solve1(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        //For approach 1(Memoization) and approach 2(Tabulation):
        vector<int> dp(n+1, -1);
        return solve2(n, dp);
    }
};