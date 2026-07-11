class Solution {
public:
    int maxElement(vector<int>& nums){
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }

    long long totalWeights(vector<int>& nums){
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }

    int helperFunc(vector<int>& nums, int mid, int days){
        int n = nums.size();
        int d = 1;
        long long sum = 0;
        for(int j = 0; j < n; j++){
            sum += nums[j];
            if(sum > mid){
                sum = nums[j];
                d++;
            }
            if(d > days) break;
        }
        return d;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        //since in example output, every output is more than the max element of the array, so we can take min element as greatest element and max element as total sum of weights of packages.

        // Brute force solution: SC: O(n*(maximum - minimum)) and TC: O(1)
        // int n = weights.size();
        // int minimum = maxElement(weights);
        // long long maximum = totalWeights(weights);
        // for(int i = minimum; i <= maximum; i++){
        //     long long sum = 0;
        //     int d = 1;
        //     for(int j = 0; j < n; j++){
        //         sum += weights[j];
        //         if(sum > i){
        //             sum = weights[j];
        //             d++;
        //         }
        //         if(d > days) break;
        //     }
        //     if(d <= days) return i;
        // }
        // return -1;


        //Optimal solution: SC: O(n*log(maximum - minimum)) and TC: O(1)
        int n = weights.size();
        int low = maxElement(weights);
        long long high = totalWeights(weights);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            int d = helperFunc(weights, mid, days);
            if(d <= days){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};