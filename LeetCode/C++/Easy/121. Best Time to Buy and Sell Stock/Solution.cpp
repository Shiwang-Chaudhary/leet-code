class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int purchase = 0;
        int sell = 0;
        int temppurc = 0;
        int tempsell = 0;
        for(int i=1; i<n; i++){
            if(prices[i]<prices[i-1]){
                purchase = i+1;
                temppurc = prices[i];
                tempsell = temppurc;
            }
            if(tempsell<prices[i]){
                sell = i+1;
                tempsell = prices[i];
            }
        }
        return sell;
    }
};