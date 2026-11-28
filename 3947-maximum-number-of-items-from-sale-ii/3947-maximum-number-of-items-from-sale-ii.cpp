class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;
        int maxFactor = 0;

        vector<int> freq(n + 1, 0);

        // Count factors and find minimum price
        for (int i = 0; i < n; i++) {
            int f = items[i][0];
            int p = items[i][1];

            freq[f]++;
            minPrice = min(minPrice, p);
            maxFactor = max(maxFactor, f);
        }

        // Calculate number of free-item opportunities
        vector<int> gain(maxFactor + 1, 0);

        for (int f = 1; f <= maxFactor; f++) {
            for (int j = f; j <= maxFactor; j += f) {
                gain[f] += freq[j];
            }
            gain[f]--; // Exclude itself
        }

        // Sort by price
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        long long ans = 0;

        // Buy items that give bonus (2 items for 1 purchase)
        for (int i = 0; i < n; i++) {
            int f = items[i][0];
            int p = items[i][1];

            if (p > 2 * minPrice)
                break;

            int take = min(gain[f], budget / p);

            ans += 2LL * take;
            budget -= take * p;
        }

        // Buy remaining items at cheapest price
        ans += budget / minPrice;

        return (int)ans;
    }
};