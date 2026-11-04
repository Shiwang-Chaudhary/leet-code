class Solution {
public:

    int recursion(int index, int start, vector<int>& nums){
        if(index < start) return 0;
        int rob = nums[index] + recursion(index - 2, start, nums);
        int skip = 0 + recursion(index-1, start, nums);
        return max(rob, skip);
    }

    int memoization(int index, int start, vector<int>& dp, vector<int>& nums){
        if(index < start) return 0;
        if(dp[index] != -1) return dp[index];
        int rob = nums[index] + memoization(index-2, start, dp, nums);
        int skip = 0 + memoization(index-1, start, dp, nums);
        dp[index] = max(rob, skip);
        return dp[index];
    }

    int tabulation(int start, int end, vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[start] = nums[start];
        if(start + 1 <= end) dp[start+1] = max(dp[start], nums[start + 1]);
        for(int i = start + 2; i <= end; i++){
            int rob = nums[i] + dp[i-2];
            int skip = 0 + dp[i-1];
            dp[i] = max(rob, skip);
        }
        return dp[end];
    }

    int optimized(int start, int end, vector<int>& nums){
        int n = nums.size();
        int prev1 = 0;
        int prev2 = nums[start];
        int current = 0;
        if(start+1 <= end) prev1 = max(nums[start+1], prev2);
        for(int i = start + 2; i <= end; i++){
            int rob = nums[i] + prev2;
            int skip = 0 + prev1;
            current = max(rob, skip);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        //Method 1: Recursion: TC: O(2^n) and SC: O(n)[recursion stack]
        // int n = nums.size();
        // //CASE 1: picking last element but not first so index = n-1 and start = 1 (not 0)
        // int case1 = recursion(n-1, 1, nums);
        // //CASE 2: picking first element but not last so index = n-2 and start = 0 
        // int case2 = recursion(n-2, 0, nums);
        // return max(case1, case2);

        //Method 2: Memoization: TC: O(n) and SC: O(n) + O(n)[Recursion stack and Dp array]
        // int n = nums.size();
        // if(n == 1) return nums[0];
        // //DP arrays must be different because both cases have different starting and ending points
        // vector<int> dp1(n, -1); // for case 1 (ask chatgpt)
        // vector<int> dp2(n, -1); // for case 2 (ask chatgpt)        
        // //CASE 1: picking last element but not first so index = n-1 and start = 1 (not 0)
        // int case1 = memoization(n-1, 1, dp1, nums);
        // //CASE 2: picking first element but not last so index = n-2 and start = 0 
        // int case2 = memoization(n-2, 0, dp2, nums);
        // return max(case1, case2);

        //Method 3: Tabulation:
        // int n = nums.size();
        // if(n == 1) return nums[0];
        // int case1 = tabulation(0, n-2, nums);
        // int case2 = tabulation(1, n-1, nums);
        // return max(case1, case2);

        //Method 4: Optimized Tabulation: 
        int n = nums.size();
        if(n == 1) return nums[0];
        int case1 = optimized(0, n-2, nums);
        int case2 = optimized(1, n-1, nums);
        return max(case1, case2);
    }
};