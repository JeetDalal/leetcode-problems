class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        def fibo(n):
            phi = 1.61803398874989484820
            phi2 = (phi - 1) * (-1)
            return int(((phi ** n) - (phi2 ** n))//2.236067977)
        if n <= 2:
            return n
        return fibo(n + 1)
            
        