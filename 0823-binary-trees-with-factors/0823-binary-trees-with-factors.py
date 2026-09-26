from typing import List

class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        MOD = 10**9 + 7

        arr.sort()

        dp = {}

        for i in range(len(arr)):
            x = arr[i]

            # A single node is always a valid tree
            dp[x] = 1

            for j in range(i):
                a = arr[j]

                # If a divides x, check whether x/a exists
                if x % a == 0:
                    b = x // a

                    if b in dp:
                        dp[x] += dp[a] * dp[b]

            dp[x] %= MOD

        return sum(dp.values()) % MOD