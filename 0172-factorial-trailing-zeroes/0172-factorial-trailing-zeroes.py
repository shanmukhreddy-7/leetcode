class Solution(object):
    def trailingZeroes(self, n):
        ans = 0

        while n:
            n //= 5
            ans += n

        return ans