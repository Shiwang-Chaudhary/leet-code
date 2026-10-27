class Solution {
public:
    //Check out excalidraw file for this problem and watch striver's video:

    //Recursion(index) represent maxmoney from 0th to (index)th by selecting non continuous subsequences
    //here, 0 can or cant be selected and (index)th can or cannot be selected
    int recursion(int index, vector<int>& nums){
        // if(index >= nums.size()) return 0;
        // int rob = recursion(index + 2, nums) + nums[index];
        // int skip = recursion(index + 1, nums);
        // return max(rob, skip);
        //if i
        if(index == 0) return nums[0];
        if(index < 0) return 0;
        //if current index is picked then its last picked index must be index - 2 since consecutive sequences are not allowed, also current index is picked so its value is also added
        int rob = nums[index] + recursion(index - 2, nums);
        //if current index isnt picked then its last picked index must be index - 1
        int skip = 0 + recursion(index - 1, nums);
        return max(rob, skip);
    }

    int memoization(int index, vector<int>&dp, vector<int>& nums){
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int rob =  nums[index] + memoization(index + 2, dp, nums);
        int skip = 0 + memoization(index + 1, dp, nums);
        dp[index] = max(rob, skip);
        return dp[index];
    }

    // int tabulation(vector<int>& nums){
    //     vector<int> dp(n, -1);
    // }

    int rob(vector<int>& nums) {
        //Method 1: Recursion: TC: O(2^n) and SC: O(n) [Recursion stack]
        // return recursion(0, nums);

        //Method 2: Memoization: TC: O(n) and SC: O(n) [Recursion stack]
        vector<int> dp(nums.size(), -1);
        return memoization(0, dp, nums);
    }
};