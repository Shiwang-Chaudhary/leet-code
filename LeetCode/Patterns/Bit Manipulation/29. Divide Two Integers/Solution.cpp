class Solution {
public:
    int divide(int dividend, int divisor) {
        int i = 0;
        int sum = 0;
        long long dividendDummy = dividend;
        long long divisorDummy = divisor;
        if(dividendDummy < 0){
            dividendDummy = -dividendDummy;
        }
        if(divisorDummy < 0){
            divisorDummy = -divisorDummy;
        }
        while(sum + divisorDummy < dividendDummy){
            i++;
            sum = sum + 3;
        }
        if(dividend < 0 || divisor < 0){
            return -i;
        }
        if(dividend < 0 && divisor < 0) return i;
        return i;
    }
};