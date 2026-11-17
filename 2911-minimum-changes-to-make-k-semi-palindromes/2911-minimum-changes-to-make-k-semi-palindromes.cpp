
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        const int INF = 1e9;

        // Stage 1: Precompute semi-palindrome costs
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;

                // Try every proper divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;
                    int m = len / d;

                    // Check each residue sequence
                    for (int r = 0; r < d; r++) {

                        for (int t = 0; t < m / 2; t++) {

                            int left = i + r + t * d;
                            int right = i + r + (m - 1 - t) * d;

                            if (s[left] != s[right])
                                changes++;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // Stage 2: DP
        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {

            for (int i = 2 * p; i <= n; i++) {

                for (int j = 2 * (p - 1); j <= i - 2; j++) {

                    if (dp[j][p - 1] == INF)
                        continue;

                    dp[i][p] = min(
                        dp[i][p],
                        dp[j][p - 1] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
