from functools import lru_cache
from typing import List

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)

        suffix = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        @lru_cache(None)
        def dp(i, M):
            if i >= n:
                return 0

            if i + 2 * M >= n:
                return suffix[i]

            ans = 0
            for X in range(1, 2 * M + 1):
                ans = max(ans, suffix[i] - dp(i + X, max(M, X)))

            return ans

        return dp(0, 1)