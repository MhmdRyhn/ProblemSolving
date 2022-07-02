"""
Solved using Kadane's algorithm. Kadane's algorithm finds the
`maximum sum subarray`.

A simple explanation of Kadane's algorithm:
https://codeforces.com/blog/entry/13713
"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        prices_len = len(prices)
        cur_max = 0
        ans = 0
        for i in range(prices_len - 1):
            cur_max += prices[i + 1] - prices[i]
            cur_max = max(0, cur_max)
            ans = max(ans, cur_max)
        return ans


if __name__ == '__main__':
    print(Solution().maxProfit([7, 1, 5, 3, 6, 4]))
