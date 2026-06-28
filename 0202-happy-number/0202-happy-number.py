class Solution(object):
    def isHappy(self, n):
        def getNext(num):
            total = 0
            while num:
                digit = num % 10
                total += digit * digit
                num //= 10
            return total

        slow = n
        fast = getNext(n)

        while fast != 1 and slow != fast:
            slow = getNext(slow)
            fast = getNext(getNext(fast))

        return fast == 1