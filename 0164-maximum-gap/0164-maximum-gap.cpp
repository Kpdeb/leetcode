#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        if (minVal == maxVal) return 0;

        // Calculate bucket size and count
        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        // Each bucket stores its min and max elements
        vector<int> minBucket(bucketCount, INT_MAX);
        vector<int> maxBucket(bucketCount, INT_MIN);

        for (int x : nums) {
            int idx = (x - minVal) / bucketSize;
            minBucket[idx] = min(minBucket[idx], x);
            maxBucket[idx] = max(maxBucket[idx], x);
        }

        // Scan buckets to find the max gap
        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; i++) {
            // Skip empty buckets
            if (minBucket[i] == INT_MAX) continue;

            // Gap is between current bucket's min and previous bucket's max
            maxGap = max(maxGap, minBucket[i] - prevMax);
            prevMax = maxBucket[i];
        }

        return maxGap;
    }
};