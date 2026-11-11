
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long common = min(need1, need2);

        long long ans = 0;

        ans += common * min((long long)costBoth,
                            (long long)cost1 + cost2);

        ans += (long long)max(0, need1 - need2) *
               min(cost1, costBoth);

        ans += (long long)max(0, need2 - need1) *
               min(cost2, costBoth);

        return ans;
    }
};
