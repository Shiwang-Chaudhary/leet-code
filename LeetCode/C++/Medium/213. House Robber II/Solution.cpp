class Solution {
public:

    int recursion(int index, int start, vector<int>& nums){
        if(index < start) return 0;
        int rob = nums[index] + recursion(index - 2, start, nums);
        int skip = recursion(index-1, start, nums);
        return max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int case1 = recursion(n-1, 1, nums);
        int case2 = recursion(n-2, 0, nums);
        return max(case1, case2);
    }
};