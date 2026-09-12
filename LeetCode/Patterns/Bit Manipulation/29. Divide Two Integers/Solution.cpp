class Solution {
public:
    int divide(int dividend, int divisor) {
        // Brute force: TC: O(|dividend|), SC: O(1)        
    //     long long i = 0;
    //     long long sum = 0;
    //     bool negative = (dividend < 0) ^ (divisor < 0);
    //     long long dividendDummy = dividend;
    //     long long divisorDummy = divisor;

    //     if(dividendDummy < 0){
    //         dividendDummy = -dividendDummy;
    //     }
    //     if(divisorDummy < 0){
    //         divisorDummy = -divisorDummy;
    //     }
    //     while(sum + divisorDummy <= dividendDummy){
    //         i++;
    //         sum = sum + divisorDummy;
    //     }
    //    return negative ? -i : i;

        //Optimal solution: TC: O(log(dividend)) and SC: O(1)
        long long sum = 0;
        long long i = 0;
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long long dummyDividend = dividend;
        long long dummyDivisor = divisor;
        long long quotient = 0;
        if(dummyDividend < 0) dummyDividend = -dummyDividend;
        if(dummyDivisor < 0) dummyDivisor = -dummyDivisor;

        while(dummyDividend >= dummyDivisor){
            if(sum + (dummyDivisor << i) > dummyDividend){
                dummyDividend -= sum;
                sum = 0;
                i = 0;
            }else{
                sum += dummyDivisor << i;
                quotient += 1 << i;
                i++;
            }
        }
        return isNegative ? -(quotient) : quotient;
    }
};