
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Store {digit sum, number, original index}
        vector<array<int, 3>> arr;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            arr.push_back({sum, nums[i], i});
        }

        // Sort by digit sum, then by number
        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        // Count cycles in the permutation
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                cycleSize++;

                j = arr[j][2];
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
