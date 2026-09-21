class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        int sum = 0;
        for (int x : rolls) {
            sum += x;
        }

        int totalSum = mean * (m + n);
        int missingSum = totalSum - sum;

        // Impossible if sum cannot be achieved with n dice
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }

        vector<int> ans(n, 1);

        // Remaining amount after giving each die value 1
        int extra = missingSum - n;

        for (int i = 0; i < n && extra > 0; i++) {
            int add = min(5, extra);
            ans[i] += add;
            extra -= add;
        }

        return ans;
    }
};