class Solution {
public:

    int maxElement(vector<int>& nums){
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, nums[i]);
        }
        return ans;
    }

    int findKthPositive(vector<int>& nums, int k) {
//         The formula is:

// missing = arr[i] - (i + 1)

// It works only if:

// The array is sorted in increasing order.
// The array contains distinct positive integers.
// The indexing is 0-based.

// These are exactly the constraints of LeetCode 1539.




        //Brute force: TC: O(n + k) and SC: O(1)
    //    int n = nums.size();
    //    int current = 1;
    //    int index = 0;
    //    int missing = 0;
    //    while(missing < k){
    //         if(index < n && current == nums[index]){
    //             index++;
    //         }else{
    //             missing++;
    //             if(missing == k) return current;
    //         }
    //         current++;
    //    }
    //    return current-1;

        //Brute force's Striver solution: TC: O(n) and SC: O(1)
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     if(nums[i] <= k){
        //         k++;
        //     }else{
        //         return k;
        //     }
        // }
        // return k;

        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int totalmissing = nums[mid] - (mid+1);
            if(totalmissing < k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        //Ans should be below:
        // int missingtillHigh = nums[high] - (high + 1);
        // int more = k - missingtillHigh;
        
        //but we did low + k because:
        /*
        //optimal solution: why we did ans = low+k at the end instead of ans = arr[high] + more?
        reason: more = k - missingtillhigh, missingtillhigh = arr[high] - (high+1),
        so, ans = arr[high] + (k - missingtillhigh) => ans = arr[high] + k - (arr[high] - (high+1))
        so, ans becomes, ans = arr[high] + k - arr[high] + high + 1;
        cancel out arr[high]: ans = high + k + 1;
        since low is always 1 more than high, we can say that: ans = low + k;
        */
        return low + k;
    }
};