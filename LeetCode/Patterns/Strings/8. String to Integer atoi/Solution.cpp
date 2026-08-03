class Solution {
public:
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    int myAtoi(string s) {
        //Brute force: TC:O(n) and SC:O(n) because of using temp, we avoid that in optimal solution
        // int n = s.size();
        // long long ans = 0;
        // string temp;
        // int i = 0;
        // bool isNegative = false;

        // // Skip leading spaces
        // while (i < n && s[i] == ' ') i++;
        // // Check for sign
        // if (i < n && s[i] == '+')
        //     i++;
        // else if (i < n && s[i] == '-') {
        //     isNegative = true;
        //     i++;
        // }
        // // Skip leading zeros
        // while (i < n && s[i] == '0') i++;
        // if (i == n) return 0;
        // // If first non-zero character isn't a digit
        // if (!isDigit(s[i])) return 0;
        // // Store all digits
        // while (i < n && isDigit(s[i])) {
        //     temp += s[i];
        //     i++;
        // }
        // // Convert temp to integer (cant use stoi)
        // for (char ch : temp) {
        //     int digit = ch - '0';
        //     // Overflow check
        //     if (ans > INT_MAX / 10 ||
        //         (ans == INT_MAX / 10 && digit > (isNegative ? 8 : 7))) {
        //         return isNegative ? INT_MIN : INT_MAX;
        //     }
        //     ans = ans * 10 + digit;
        // }
        // if (isNegative) ans = -ans;
        // return (int)ans;

        //Optimal solution: TC: O(n) and SC:O(n) because of temp string
        int n = s.size();
        long long ans = 0;
        string temp;
        int i = 0;
        bool isNegative = false;
        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;
        // Check for signs
        if (i < n && s[i] == '+') i++;
        else if (i < n && s[i] == '-') {
            isNegative = true;
            i++;
        }
        //Skip leading zeroes
        while (i < n && s[i] == '0') i++;
        if (i == n) return 0;
        //If current number isnt digit then return 0
        if (!isDigit(s[i])) return 0;
        //Store numbers in temp var
        while (i < n && isDigit(s[i])) {
            //We cant use stoi here
            int digit = s[i] - '0';
            //Overflow check:
            // INT_MAX = 2147483647
            // INT_MIN = -2147483648
            //look at last digit of intmax and intmin thats why we did digit>7/8
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > ((isNegative) ? 8 : 7))) {
                return (isNegative) ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + digit;
            i++;
        }

        if (isNegative) ans = -ans;
        return (int)ans;
    }
};