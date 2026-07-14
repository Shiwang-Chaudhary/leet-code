class Solution {
public:

    long long totalSum(vector<int>& nums){
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }
    //Returns minimum sub array possible:
    // if it returns 2 then 3,4.. might also be possible.
    //lets say it returns 2 and m = 3 then we do subarray <= m that means if minimum is 2 then 3, 4 or more might also possible
    int countminimumSubArray(vector<int>& nums, int i){
        int subarray = 1;
        int sum = 0;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            if(sum > i){
                subarray++;
                sum = nums[j];
            }
        }
        return subarray;
    }

    int maxElement(vector<int>& nums){
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }
    
    int splitArray(vector<int>& nums, int k) {
        // int n = nums.size();
        // int minSum = maxElement(nums);
        // int maxSum = totalSum(nums);
        // if(k > n) return -1;
        // for(int i = minSum; i <= maxSum; i++){
        //     int subarray = countminimumSubArray(nums, i);
        //     if(subarray <= k) return i;
        // }
        // return -1;

        int n = nums.size();
        int low = maxElement(nums);
        int high = totalSum(nums);
        if(k > n) return -1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            int subarray = countminimumSubArray(nums, mid);
            if(subarray <= k){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};