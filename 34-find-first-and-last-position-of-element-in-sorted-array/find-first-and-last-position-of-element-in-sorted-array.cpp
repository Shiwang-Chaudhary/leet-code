class Solution {
public:

    int upperBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int lowerBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }

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

        //Optimal solution: TC: O(logn) and SC: O(1).
        // int n = nums.size();
        // int low = 0;
        // int high = n-1;
        // int first = -1;
        // int last = -1;
        // int ans = -1;
        // while(low<=high){
        //     int mid = low + (high-low)/2;
        //     if(nums[mid] == target){
        //         ans = mid;
        //         high = mid - 1;
        //     }else if(nums[mid] < target){
        //         low = mid + 1;
        //     }else{
        //         high = mid - 1;
        //     }
        // }
        // first = ans;
        // ans = -1;
        // low = 0;
        // high = n-1;
        // while(low<=high){
        //     int mid = low + (high-low)/2;
        //     if(nums[mid] == target){
        //         ans = mid;
        //         low = mid + 1;
        //     }else if(nums[mid] < target){
        //         low = mid + 1;
        //     }else{
        //         high = mid - 1;
        //     }
        // }
        // last = ans;
        // return {first, last};

        //Optimal solution 2 using lower and upper bound:
        int first = lowerBound(nums, target);
        if(first == nums.size() || nums[first] != target){
            return{-1,-1};
        }
        int last = upperBound(nums, target)-1;
        return {first, last};
    }
};