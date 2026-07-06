class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Brute force solution:
        //  int n = nums.size();
        //  for(int i = 0; i < n; i++){
        //      if(nums[i] == target){
        //          return i;
        //      }
        //  }
        //  return -1;

        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int index = -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            //left half is sorted
            if(nums[low] <= nums[mid]){
                //element lies in left sorted half
                if(nums[low]<= target && target < nums[mid]){
                    high = mid - 1;
                }else{//element lies in right unsorted half
                    low = mid + 1;
                }
            }else{//right half is sorted

                //element lies in right sorted half
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }else{//element lies in left unsorted half
                    high = mid - 1;
                }
            }
        }
        return index;
    }
};