class Solution {
public:

    int maxElement(vector<int>& nums){
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }

    int minElement(vector<int>& nums){
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            ans = min(ans, nums[i]);
        }
        return ans;
    }

    int noOfBucket(vector<int>& bloomDay, int mid, int k){
        int flower = 0;
        int bucket = 0;
        for(auto day : bloomDay){
            if(day <= mid){
                flower++;
                if(flower == k){
                    bucket++;
                    flower = 0;
                }
            }else{
                flower = 0;
            }
        }
        return bucket;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        //Brute force: TC : O((maxDay-minDay)*n) and SC: O(1).
        // int n = bloomDay.size();
        // int minDay = minElement(bloomDay);
        // int maxDay = maxElement(bloomDay);
        // //if required flowers are more than the given flowers
        // if(1LL * m * k > n) return -1;
        // for(int day = minDay; day <= maxDay; day++){
        //     int flower = 0;
        //     int bucket = 0;
        //     for(int j = 0; j < n; j++){
        //         if(bloomDay[j] <= day){
        //             flower++;
        //             if(flower == k){
        //                 bucket++;
        //                 flower = 0;
        //             }
        //         }else{
        //             flower = 0;
        //         }
        //     }
        //     if(bucket >= m) return day;
        // }
        // return -1;

        //Optimal solution: O(n*log())
        int n = bloomDay.size();
        int low = minElement(bloomDay); //min day
        int high = maxElement(bloomDay);// max day
        int ans = 0;
        if(1LL * m * k > n) return -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int flower = 0;
            int bucket = 0;
            bucket = noOfBucket(bloomDay, mid, k);
            if(bucket >= m){
                ans = mid;
                //that means ans will either be mid or left half of mid,because we have to find the minimum no of days and if we go on right half then days will only increase, thats why we have to check on left side.
                high = mid - 1;
            }else{
                //that means ans will be on right because current mid doesnt have enough days to make required no. of buckets therefore minimum required no. of day will be more than current mid so we move to right half.
                low = mid + 1;
            }
        }
        return ans;
    }   
};