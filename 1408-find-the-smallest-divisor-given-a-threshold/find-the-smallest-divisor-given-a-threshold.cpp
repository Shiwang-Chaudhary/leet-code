class Solution {
public:
    int maxElement(vector<int>& nums){
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }
    int helperFunc(vector<int>& nums, int mid){
        long long sum = 0;
        int n = nums.size();
        for(int j = 0; j < n; j++){
            int division = (nums[j] + mid - 1)/mid;
            sum += division;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // int n = nums.size();
        // int maximum = maxElement(nums);
        // for(int i = 1; i <= maximum; i++){
        //     long long sum = 0;
        //     for(int j = 0; j < n; j++){
        //         int division = (nums[j] + i - 1)/i;
        //         sum += division;
        //     }
        //     if(sum <= threshold){
        //         return i;
        //     }
        // }
        // return -1;

        int n = nums.size();
        int low = 1;
        int high = maxElement(nums);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long sum = helperFunc(nums, mid);
            if(sum <= threshold){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};