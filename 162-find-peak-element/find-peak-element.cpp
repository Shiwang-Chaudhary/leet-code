class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //Brute force: TC: O(n) and SC: O(1)
        // int n = nums.size();
        // if(n == 1) return 0;
        // if(nums[0] > nums[1]) return 0;
        // if(nums[n-2] < nums[n-1]) return n-1;
        // for(int i = 1; i < n-1; i++){
        //     if(nums[i-1] < nums[i] && nums[i] > nums[i+1]) return i;
        // }
        // return -1;
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-2] < nums[n-1]) return n-1;
        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            //Upward slope
            if(nums[mid] < nums[mid+1]){
                //move right:
                low = mid + 1;
            }else{
                //downward slope
                //move left:
                high = mid - 1;
            }
        }
        return -1;
    }
};