class Solution:
    def subsets(self, nums):
        result = []

        def backtrack(index, subset):
            result.append(subset[:])

            for i in range(index, len(nums)):
                subset.append(nums[i])
                backtrack(i + 1, subset)
                subset.pop()

        backtrack(0, [])
        return result