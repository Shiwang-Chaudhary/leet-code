class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Brute force: TC: O(n) and SC: O(1)
        // int n = nums.size();
        // int i = 0;
        // for(i = 0; i < n; i++){
        //     if(nums[i]>=target){
        //         return i;
        //     }
        // }
        //// return n;

        //Optimal solution : TC: O(logn) and SC: O(1)
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=target) {
                ans = min(ans, mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};