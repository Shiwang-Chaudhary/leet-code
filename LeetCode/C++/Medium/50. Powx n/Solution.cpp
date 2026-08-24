class Solution {
public:
    double myPow(double x, int n) {
        //Brute force: O(n) and O(n)
        // long double val = 0.0;
        // if(n == 0) return 1;
        // else if(n < 0){
        //     val = myPow(x, n + 1);
        //     val = val/x;
        // }else{
        //     val = myPow(x, n - 1);
        //     val = val * x;
        // }
        // return val;

        //Optimal solution: TC: O(logn) and sc: O(logn)
        long double ans = 0.0;
        long double val = 0.0;
        long int N = n;
        if(N < 0){
            x = 1/x;
            N = -N;
        }
        if(N == 0) return 1;
        //Even case...
        if(N % 2 == 0){
            val = myPow(x, N/2);
            return val * val;
        }
        //Odd case
        val = myPow(x, N/2);
        return x * val * val;
    }
};