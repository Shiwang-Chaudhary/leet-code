class Solution {
public:

    int recursion(int index, vector<int>& nums){
        if(index >= nums.size()) return 0;
        int rob = recursion(index + 2, nums) + nums[index];
        int skip = recursion(index + 1, nums);
        return max(rob, skip);
    }

    int memoization(int index, vector<int>&dp, vector<int>& nums){
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int rob = memoization(index + 2, dp, nums) + nums[index];
        int skip = memoization(index + 1, dp, nums);
        dp[index] = max(rob, skip);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        //Method 1: Recursion: TC: O(2^n) and SC: O(n) [Recursion stack]
        // return recursion(0, nums);

        //Method 2: Memoization: TC: O(n) and SC: O(n) [Recursion stack]
        vector<int> dp(nums.size(), -1);
        return memoization(0, dp, nums);
    }
};