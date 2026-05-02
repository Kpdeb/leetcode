class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)
        total_sum = sum(nums)
        
        # F(0)
        F = sum(i * num for i, num in enumerate(nums))
        max_value = F
        
        # Compute F(1) to F(n-1)
        for k in range(1, n):
            F = F + total_sum - n * nums[n - k]
            max_value = max(max_value, F)
        
        return max_value