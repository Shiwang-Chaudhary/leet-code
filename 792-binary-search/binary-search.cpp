class Solution {
public:
    //Recursive binary search:
    // int binarySearch(vector<int>& nums, int low, int high, int target){
    //     int mid = low + (high-low)/2;
    //     if(low>high){
    //         return -1;
    //     }
    //     if(nums[mid] == target){
    //         return mid;
    //     }else if(target > nums[mid]){
    //         return binarySearch(nums, mid+1, high, target);
    //     }
    //     //target<nums[mid]
    //     return binarySearch(nums, low, mid-1, target);
    // }

    int search(vector<int>& nums, int target) {
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == target){
        //         return i;
        //     }
        // }
        // return -1;
        //Recursive binary search:
        // return binarySearch(nums, 0, nums.size()-1, target);

        //Iterative binary search:
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }else if(target > nums[mid]){
                low = mid+1;
            }else{
                //// when target < nums[mid]
                high = mid - 1;
            }
        }
        return -1;
    }
};