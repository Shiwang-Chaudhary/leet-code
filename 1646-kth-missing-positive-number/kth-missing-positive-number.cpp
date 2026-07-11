class Solution {
public:

    int maxElement(vector<int>& nums){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }

    int findKthPositive(vector<int>& nums, int k) {
       int n = nums.size();
       int current = 1;
       int index = 0;
       int missing = 0;
       while(missing < k){
            if(index < n && current == nums[index]){
                current++;
                index++;
            }else{
                missing++;
                if(missing == k) return current;
                current++;
            }
       }
       return current-1;
    }
};