class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;     // Treat '*' as ')'
                high++;    // Treat '*' as '('
            }

            // Even the most optimistic case has too many ')'
            if (high < 0)
                return false;

            // low cannot be negative
            low = max(low, 0);
        }

        // If zero opens are possible, the string can be valid
        return low == 0;
    }
};