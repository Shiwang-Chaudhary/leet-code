class Solution {
public:
    //Same as Leetcode number: 50. Pow(x, n)...
    long long myPow(long long x, long long n){
        const long long MOD = 1000000007;
        long long result = 0;
        if(n == 0) return 1;
        long long val = myPow(x, n/2);
        result = (val * val) % MOD;
        if(n % 2 == 1) result = (result * x) % MOD;
        return result;
    }

    int countGoodNumbers(long long n) {
        // //Brute force: O(n) and SC: O(1)
        // long long ans = 1;
        // //we use MOD because answer can be very very large so we need to keep it under MOD
        // const long long MOD = 1000000007;
        // long long size = n/2;
        // long long evensize = n/2;
        // long long oddsize = n/2;
        // if(n % 2 == 0){
        //     evensize = size;
        //     oddsize = size;
        // }else{
        //     evensize = size + 1;
        //     oddsize = size;
        // }
        // //5 means at even places 5 different even numbers can be possible and these are:
        // // 0, 2, 4, 6, 8
        // for(int i = 0; i < evensize; i++){
        //     ans = (ans * 5) % MOD;
        // }
        // //4 means at odd places 4 different prime numbers can be possible and these are:
        // // 2, 3, 5, 7
        // for(int i = 0; i < oddsize; i++){
        //     ans = (ans * 4) % MOD;
        // }
        // return ans;

        //Better solution: TC: O(logn) and SC: O(logn)
        const long long MOD = 1000000007;
        if(n == 0) return 1;
        long long val = myPow(20, n/2);
        //if n is even then multiply extra 5 otherwise dont
        if(n % 2 == 1){
            val = (val * 5) % MOD;
        }
        return val;
    }
};