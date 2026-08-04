class Solution {
public:
    bool isPalindrome(int x) {
        long long ans = 0;
        if(x < 0) return false;
        int extra = x;
        while(extra > 0){
            int digit = extra % 10;
            ans = ans * 10 + digit;
            extra = extra/10;
        }
        return ans == x;
    }
};