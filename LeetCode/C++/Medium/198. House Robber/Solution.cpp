class Solution {
public:

    int recursion(int index, vector<int>& nums){
        if(index >= nums.size()) return 0;
        int rob = recursion(index + 2, nums) + nums[index];
        int skip = recursion(index + 1, nums);
        return max(rob, skip);
    }

    int rob(vector<int>& nums) {
        //Method 1: Recursion: TC: O(2^n) and SC: O(n) [Recursion stack]
        return recursion(0, nums);
    }
};