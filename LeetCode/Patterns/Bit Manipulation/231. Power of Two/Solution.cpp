class Solution {
public:
    bool isPowerOfTwo(int n) {
        //For example: n = 16, binary = 10000 and n-1 = 15 => binary = 01111 so 16 & 15 = 0, if ans = 0 then it is power of 2, because every power of 2 has only 1 bit as 1 and every other bit as 0
        if(n <= 0) return false;
        if((n & n-1) == 0) return true;
        return false;
    }
};