class Solution:
    def combinationSum2(self, candidates, target):
        candidates.sort()
        ans = []

        def backtrack(start, target, path):
            if target == 0:
                ans.append(path[:])
                return

            for i in range(start, len(candidates)):
                
                # Skip duplicate numbers at the same level
                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                # No point continuing
                if candidates[i] > target:
                    break

                path.append(candidates[i])

                # i + 1 because each number can be used only once
                backtrack(i + 1, target - candidates[i], path)

                path.pop()

        backtrack(0, target, [])
        return ans