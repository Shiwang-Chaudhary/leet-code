class Solution {
public:

    //Approach 3: Optimized Tabulation: TC: O(n) and SC: O(1)
    int solve3(int n){
        if(n <= 2) return n;
        int prev1 = 2; //prev1 means i-1
        int prev2 = 1; //prev2 means i-2
        int current = 0;
        for(int i = 3; i <= n; i++){
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }

    //Approach 2: Tabulation approach: TC: O(n) and SC: O(n) [dp array]
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
        // vector<int> dp(n+1, -1);
        //For approach 3 (Optimized Tabulation):
        return solve3(n);
    }
};