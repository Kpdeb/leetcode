class Solution:
    def findLUSlength(self, strs: List[str]) -> int:

        def is_subsequence(a, b):
            i = 0

            for ch in b:
                if i < len(a) and a[i] == ch:
                    i += 1

            return i == len(a)

        answer = -1

        for i in range(len(strs)):
            uncommon = True

            for j in range(len(strs)):
                if i != j and is_subsequence(strs[i], strs[j]):
                    uncommon = False
                    break

            if uncommon:
                answer = max(answer, len(strs[i]))

        return answer