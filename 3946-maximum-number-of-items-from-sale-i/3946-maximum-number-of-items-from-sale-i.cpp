class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int NEG = -1e9;

        // dp[c] = maximum items using exact cost c
        // from already processed item types
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            // Count free items obtained from the first purchase
            int freeCnt = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeCnt++;
                }
            }

            // buy[c] = best result where current item
            // has been purchased at least once
            vector<int> buy(budget + 1, NEG);

            for (int c = price; c <= budget; c++) {

                // Buy the first copy of this item
                if (dp[c - price] != NEG) {
                    buy[c] = max(
                        buy[c],
                        dp[c - price] + 1 + freeCnt
                    );
                }

                // Buy another copy of the same item
                if (buy[c - price] != NEG) {
                    buy[c] = max(
                        buy[c],
                        buy[c - price] + 1
                    );
                }
            }

            // Either skip current item or buy it
            for (int c = 0; c <= budget; c++) {
                dp[c] = max(dp[c], buy[c]);
            }
        }

        // We can spend at most budget
        int ans = 0;

        for (int c = 0; c <= budget; c++) {
            ans = max(ans, dp[c]);
        }

        return ans;
    }
};