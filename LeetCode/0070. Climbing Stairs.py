"""
https://leetcode.com/problems/climbing-stairs/
"""


class Solution:
    def climbStairs(self, n: int) -> int:
        if n in [1, 2]:
            return n
        ans = 0
        a, b = 1, 2
        for i in range(n - 2):
            ans = a + b
            a, b = b, ans
        return ans


if __name__ == '__main__':
    print(Solution().climbStairs(10))
