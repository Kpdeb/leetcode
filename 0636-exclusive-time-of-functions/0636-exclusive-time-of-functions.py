class Solution:
    def exclusiveTime(self, n, logs):
        ans = [0] * n
        stack = []
        prevTime = 0

        for log in logs:
            parts = log.split(":")
            function_id = int(parts[0])
            action = parts[1]
            timestamp = int(parts[2])

            if action == "start":
                if stack:
                    ans[stack[-1]] += timestamp - prevTime

                stack.append(function_id)
                prevTime = timestamp

            else:
                ans[stack[-1]] += timestamp - prevTime + 1
                stack.pop()
                prevTime = timestamp + 1

        return ans