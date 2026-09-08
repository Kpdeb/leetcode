class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return pair<int,int>{left + 1, right - left - 1};
        };

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            auto [l1, len1] = expand(i, i);

            // Even length palindrome
            auto [l2, len2] = expand(i, i + 1);

            if (len1 > maxLen) {
                start = l1;
                maxLen = len1;
            }

            if (len2 > maxLen) {
                start = l2;
                maxLen = len2;
            }
        }

        return s.substr(start, maxLen);
    }
};