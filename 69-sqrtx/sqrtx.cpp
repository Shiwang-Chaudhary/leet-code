class Solution {
public:
    int mySqrt(int x) {
        //Brute force: TC: O(n) and SC: O(1).
        // long long ans = 0;
        // for(int i = 0; i <= x; i++){
        //     ans = 1LL*i*i;
        //     if(ans == x) return i;
        //     if(ans > x) return i-1;
        // }
        // return -1;

        //Optimal solution: TC: O(logn) and SCL O(1).
        long long ans = 0;
        int low = 0;
        int high = x;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(1LL*mid * mid > x){
                high = mid - 1;
            }else{
                //when mid * mid <= x
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};