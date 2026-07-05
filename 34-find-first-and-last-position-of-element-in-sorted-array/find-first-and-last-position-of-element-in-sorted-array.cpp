class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //Brute solution: TC: O(n) and SC: O(1).
        // int n = nums.size();
        // int first = -1;
        // int last = -1;
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == target){
        //         if(first == -1){
        //             first = i;
        //         }
        //         last = i;
        //     }
            
        // }
        // return {first, last};

        int n = nums.size();
        int low = 0;
        int high = n-1;
        int first = -1;
        int last = -1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        first = ans;
        ans = -1;
        low = 0;
        high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        last = ans;
        return {first, last};
    }
};
//5,7,7,8,8,8,8,10
//0,1,2,3,4,5,6,7



