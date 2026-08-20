class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int profit = 0;
        int purchase = nums[0];
        for(int i=1; i<n; i++){
            purchase = min(nums[i], purchase);
            //since purchase <= nums[i];
            profit = max(profit,nums[i] - purchase);
        }
        return profit;
    }
};