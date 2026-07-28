class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        string firstHalf = "";
        string middle = "";

        for (int i = 0; i < 26; i++) {
            firstHalf.append(cnt[i] / 2, char('a' + i));

            if (cnt[i] % 2)
                middle = char('a' + i);
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        return firstHalf + middle + secondHalf;
    }
};