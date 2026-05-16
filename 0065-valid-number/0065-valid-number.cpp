class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
            }
            else if (c == '+' || c == '-') {
                // Sign must be at start or right after e/E
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else if (c == '.') {
                // Dot not allowed after e or multiple dots
                if (seenDot || seenE)
                    return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                // e must appear once and after a digit
                if (seenE || !seenDigit)
                    return false;
                seenE = true;
                seenDigit = false; // reset for digits after e
            }
            else {
                return false;
            }
        }
        return seenDigit;
    }
};
