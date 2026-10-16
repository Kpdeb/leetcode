class SegmentTree:
    def __init__(self, n):
        self.n = n
        size = 4 * n
        self.sum = [0] * size
        self.sq = [0] * size
        self.lazy = [0] * size

    def apply(self, node, l, r, val):
        length = r - l + 1
        old_sum = self.sum[node]

        self.sq[node] = (
            self.sq[node] + 2 * val * old_sum
            + length * val * val
        )
        self.sum[node] = old_sum + length * val
        self.lazy[node] += val

    def push(self, node, l, r):
        if self.lazy[node] == 0 or l == r:
            return

        mid = (l + r) // 2
        val = self.lazy[node]

        self.apply(node * 2, l, mid, val)
        self.apply(node * 2 + 1, mid + 1, r, val)

        self.lazy[node] = 0

    def update(self, node, l, r, ql, qr):
        if ql <= l and r <= qr:
            self.apply(node, l, r, 1)
            return

        self.push(node, l, r)
        mid = (l + r) // 2

        if ql <= mid:
            self.update(node * 2, l, mid, ql, qr)
        if qr > mid:
            self.update(node * 2 + 1, mid + 1, r, ql, qr)

        self.sum[node] = (
            self.sum[node * 2] + self.sum[node * 2 + 1]
        )
        self.sq[node] = (
            self.sq[node * 2] + self.sq[node * 2 + 1]
        )

    def range_add(self, l, r):
        self.update(1, 0, self.n - 1, l, r)

    def squared_sum(self):
        return self.sq[1]


class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        tree = SegmentTree(n)
        last_seen = {}
        ans = 0

        for i, x in enumerate(nums):
            prev = last_seen.get(x, -1)

            tree.range_add(prev + 1, i)

            ans = (ans + tree.squared_sum()) % MOD
            last_seen[x] = i

        return ans