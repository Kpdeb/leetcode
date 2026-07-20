class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long result = 0;
        int sign = 1;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // Step 3: Convert digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Check overflow
            if (result > INT_MAX / 10 || 
               (result == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
