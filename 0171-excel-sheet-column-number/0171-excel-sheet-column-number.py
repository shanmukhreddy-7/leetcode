class Solution(object):
    def titleToNumber(self, columnTitle):
        ans = 0

        for c in columnTitle:
            ans = ans * 26 + ord(c) - ord('A') + 1

        return ans