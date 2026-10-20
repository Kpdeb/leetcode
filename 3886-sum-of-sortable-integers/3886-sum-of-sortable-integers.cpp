
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;
            int prevMax = 0;

            for (int start = 0; start < n; start += k) {
                int mn = nums[start];
                int mx = nums[start];
                int desc = 0;

                for (int i = start; i < start + k; i++) {
                    int next = (i + 1 == start + k)
                                   ? start
                                   : i + 1;

                    if (nums[i] > nums[next])
                        desc++;

                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }

                if (desc > 1 || prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};
