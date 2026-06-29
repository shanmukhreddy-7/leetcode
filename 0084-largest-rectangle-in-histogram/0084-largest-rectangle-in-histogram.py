class Solution(object):
    def largestRectangleArea(self, heights):
        stack = []
        ans = 0
        heights.append(0)
        for i in xrange(len(heights)):
            while stack and heights[stack[-1]] > heights[i]:
                h = heights[stack.pop()]
                w = i if not stack else i - stack[-1] - 1
                ans = max(ans, h * w)
            stack.append(i)
        heights.pop()
        return ans