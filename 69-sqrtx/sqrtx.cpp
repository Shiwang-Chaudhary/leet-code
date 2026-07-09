class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        for(int i = 0; i <= x; i++){
            ans = 1LL*i*i;
            if(ans == x) return i;
            if(ans > x) return i-1;
        }
        return -1;
    }
};