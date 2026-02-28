class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;

        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(a[i]);
        }

        int longest = 1;

        for (auto it : st) {
            // start of sequence
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;

                while (st.find(x + 1) != st.end()) {
                    x++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};
