from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target < nums[0] or target > nums[-1]:
            return -1
        start, end = 0, len(nums)
        while start <= end:
            mid = (start + end) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1
        return -1


if __name__ == '__main__':
    print(Solution().search([-1, 0, 3, 5, 9, 12], 9))
    print(Solution().search([-1, 0, 3, 5, 9, 12], 4))
