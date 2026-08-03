class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0;
        string temp;
        int i = 0;
        bool isNegative = false;
        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;
        if (i < n && s[i] == '+') i++;
        else if (i < n && s[i] == '-') {
            isNegative = true;
            i++;
        }
        while (i < n && s[i] == '0') i++;
        if (i == n) return 0;
        if (!isDigit(s[i])) return 0;

        while (i < n && isDigit(s[i])) {
            temp += s[i];
            i++;
        }

        //Since we cant use stoi
        for (char ch : temp) {
            if (ch == ' ' || ch == '-') continue;
            int digit = ch - '0';
            //Overflow check:
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 &&
                 digit > ((!temp.empty() && isNegative) ? 8 : 7))) {
                return (!temp.empty() && isNegative) ? INT_MIN : INT_MAX;
            }

            ans = ans * 10 + digit;
        }

        if (!temp.empty() && isNegative)
            ans = -ans;

        return ans;
    }
};