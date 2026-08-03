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

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Handle sign
        if (i < n && s[i] == '+') {
            temp = ' ';
            i++;
        } else if (i < n && s[i] == '-') {
            temp = '-';
            i++;
        }

        // Skip leading zeros
        while (i < n && s[i] == '0')
            i++;

        // No digits
        if (i == n)
            return 0;

        if (!isDigit(s[i]))
            return 0;

        // Store digits
        while (i < n && isDigit(s[i])) {
            temp += s[i];
            i++;
        }

        // Manual conversion with overflow check
        for (char ch : temp) {
            if (ch == ' ' || ch == '-')
                continue;

            int digit = ch - '0';

            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 &&
                 digit > ((!temp.empty() && temp[0] == '-') ? 8 : 7))) {
                return (!temp.empty() && temp[0] == '-') ? INT_MIN : INT_MAX;
            }

            ans = ans * 10 + digit;
        }

        if (!temp.empty() && temp[0] == '-')
            ans = -ans;

        return (int)ans;
    }
};