class Solution {
public:
    bool isPalindrome(int first, int last, const string& s) {
        while (first < last) {
            if (s[first] != s[last]) return false;
            first++;
            last--;
        }
        return true;
    }

    int expand(int left, int right, const string& s){
        int n = s.size();
        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        //Brute force: TC: O(n^3) and SC: O(1)
        // int n = s.size();
        // int start = 0;
        // int maxlen = 1;
        // string extra = s.substr(0, 1);
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         if (isPalindrome(i, j, s)) {
        //             int currentlen = j-i+1;
        //             if (currentlen > maxlen) {
        //                 maxlen = currentlen;
        //                 start = i;
        //             }
        //         }
        //     }
        // }
        // return s.substr(start,maxlen);

        //Optimal solution: TC: O(n^2) and SC: O(1)
        int n = s.size();
        int maxLen = 1;
        int start = 0;
        for(int i = 0; i < n; i++){
            int len1 = expand(i,i,s);
            int len2 = expand(i,i+1,s);
            int len = max(len1, len2);
            if(len > maxLen){
                maxLen = len;
                //Dekha tha ye formula...
                //Finding starting index of palindrome substring using length and centre element:
                start = i - (len-1)/2;
            }
        }
        return s.substr(start,maxLen);
    }
};