class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //Brute force: TC: O(n) and SC: O(1)
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == target){
        //         return true;
        //     }
        // }
        // return false;
        
        //Optimal solution:
        //same as sorted rotated array - 1 but skip the duplicate by low++ and high-- if low, mid and high, all of them have same element.
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                //Low, mid and high have same element, so skip that iteration,
                // the element woulnt be in that iteration because we already did mid == target, if it were then no need for further iteration.
                low++;
                high--;
                continue;
            }
            //Now it will be comes normal Search in Rotated Sorted Array-I
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && nums[mid] > target){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(nums[mid] < target && nums[high] >= target){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};