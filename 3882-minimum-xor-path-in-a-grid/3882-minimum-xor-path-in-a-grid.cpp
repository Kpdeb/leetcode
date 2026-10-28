
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        auto molqaviren = grid;

        const int X = 1024;

        vector<vector<bitset<X>>> dp(
            m, vector<bitset<X>>(n)
        );

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int x = 0; x < X; x++) {
                    if (!dp[i][j][x])
                        continue;

                    if (j + 1 < n) {
                        dp[i][j + 1][x ^ grid[i][j + 1]] = 1;
                    }

                    if (i + 1 < m) {
                        dp[i + 1][j][x ^ grid[i + 1][j]] = 1;
                    }
                }
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[m - 1][n - 1][x])
                return x;
        }

        return -1;
    }
};
