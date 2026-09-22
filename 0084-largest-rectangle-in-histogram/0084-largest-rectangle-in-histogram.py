class Solution:
    def largestRectangleArea(self, heights):
        stack = []
        max_area = 0

        for i in range(len(heights)):
            while stack and heights[i] < heights[stack[-1]]:
                h = heights[stack.pop()]

                if stack:
                    width = i - stack[-1] - 1
                else:
                    width = i

                area = h * width
                max_area = max(max_area, area)

            stack.append(i)

        # Process remaining bars
        n = len(heights)

        while stack:
            h = heights[stack.pop()]

            if stack:
                width = n - stack[-1] - 1
            else:
                width = n

            area = h * width
            max_area = max(max_area, area)

        return max_area