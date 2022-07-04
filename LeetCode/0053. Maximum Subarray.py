"""
Problem statement: https://leetcode.com/problems/maximum-subarray/
Solution: Kadane's algorithm
"""

from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = nums[0]
        max_so_far = nums[0]
        size_of_nums = len(nums)
        for i in range(1, size_of_nums):
            max_so_far = max(max_so_far + nums[i], nums[i], 0)
            ans = max(ans, max_so_far)
        if ans == 0:
            return max(nums)
        return ans


if __name__ == '__main__':
    # print(Solution().maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))  # Ans: 6
    # print(Solution().maxSubArray([5, 4, -1, 7, 8]))  # Ans: 23
    print(Solution().maxSubArray([-5, -4, -9, -7, -8]))  # Ans: -4
