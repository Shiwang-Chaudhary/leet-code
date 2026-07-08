class Solution {
public:
    int findMin(vector<int>& nums) {
        //Brute force: TC: O(n) and SC: O(1)
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, nums[i]);
        }
        return ans;
        //Optimal solution: O(logn)
        // int n = nums.size();
        // int low = 0;
        // int high = n-1; 
        // int ans = INT_MAX;
        // while(low<=high){
        //     //if array is already sorted:
        //     if(nums[low] <= nums[high]) {
        //         return min(ans, nums[low]);
        //     }
        //     int mid = low + (high-low)/2;
        //     //Left half is sorted
        //     if(nums[low] <= nums[mid]){
        //         ans = min(ans, nums[low]);
        //         low = mid + 1;
        //     }else{
        //         //Right half is sorted
        //         ans = min(ans, nums[mid]);
        //         high = mid - 1;
        //     }
        // }
        // return ans;
    }
};