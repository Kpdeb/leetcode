
class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // If the next character is also ')',
                // they form a valid pair.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    // Insert one ')' to complete the pair.
                    insertions++;
                }

                // Match this pair with an opening '('.
                if (open > 0) {
                    open--;
                } else {
                    // Insert one '(' because none is available.
                    insertions++;
                }
            }
        }

        // Every remaining '(' needs two ')'.
        return insertions + open * 2;
    }
};