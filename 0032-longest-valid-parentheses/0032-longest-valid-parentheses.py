class Solution(object):
    def longestValidParentheses(self, s):
        left = right = ans = 0
        for c in s:
            if c == '(':
                left += 1
            else:
                right += 1
            if left == right:
                ans = max(ans, 2 * right)
            elif right > left:
                left = right = 0
        left = right = 0
        for c in s[::-1]:
            if c == ')':
                right += 1
            else:
                left += 1
            if left == right:
                ans = max(ans, 2 * left)
            elif left > right:
                left = right = 0
        return ans