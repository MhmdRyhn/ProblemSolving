from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        Time Complexity: O(n)
        Space Complexity: O(n)
        """
        nums_index = {nums[0]: 0}
        length = len(nums)
        for i in range(1, length):
            if (another_index := nums_index.get(target - nums[i], None)) is not None:
                return [another_index, i]
            nums_index[nums[i]] = i


if __name__ == '__main__':
    print(Solution().twoSum([2, 7, 11, 15], 9))
    print(Solution().twoSum([3, 2, 4], 6))
    print(Solution().twoSum([3, 3], 6))
