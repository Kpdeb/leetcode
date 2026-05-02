class Solution:
    def rotatedDigits(self, n: int) -> int:
        good_count = 0
        
        for num in range(1, n + 1):
            s = str(num)
            is_valid = True
            has_diff = False
            
            for ch in s:
                if ch in '347':
                    is_valid = False
                    break
                if ch in '2569':
                    has_diff = True
            
            if is_valid and has_diff:
                good_count += 1
        
        return good_count