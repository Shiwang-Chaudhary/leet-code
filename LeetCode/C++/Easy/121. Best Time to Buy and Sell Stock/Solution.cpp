class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int profit = 0;
        int purchase = nums[0];
        int sell = 0;
        for(int i=1; i<n; i++){
            purchase = min(nums[i], purchase);
            sell = purchase;
            sell = max(sell,nums[i]);
            profit = max(profit,sell - purchase);
        }
        return profit;
    }
};