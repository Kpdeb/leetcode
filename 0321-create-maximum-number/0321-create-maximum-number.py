class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        def maxSubsequence(nums, k):
            stack = []
            drop = len(nums) - k
            for n in nums:
                while stack and drop > 0 and stack[-1] < n:
                    stack.pop()
                    drop -= 1
                stack.append(n)
            return stack[:k]

        def greater(a, i, b, j):
            while i < len(a) and j < len(b) and a[i] == b[j]:
                i += 1
                j += 1
            return j == len(b) or (i < len(a) and a[i] > b[j])

        def merge(a, b):
            res = []
            i = j = 0
            while i < len(a) or j < len(b):
                if greater(a, i, b, j):
                    res.append(a[i])
                    i += 1
                else:
                    res.append(b[j])
                    j += 1
            return res

        best = [0] * k
        start = max(0, k - len(nums2))
        end = min(k, len(nums1))

        for i in range(start, end + 1):
            part1 = maxSubsequence(nums1, i)
            part2 = maxSubsequence(nums2, k - i)
            candidate = merge(part1, part2)
            if candidate > best:
                best = candidate

        return best
