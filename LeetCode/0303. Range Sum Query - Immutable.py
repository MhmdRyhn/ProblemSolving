from typing import List


class NumArray:
    def __init__(self, nums: List[int]):
        self.prefix_sum = self.get_prefix_sum(nums)

    def get_prefix_sum(self, nums) -> List[int]:
        # print(nums)
        numbers_count = len(nums)
        prefix_sum = [nums[0]]
        for i in range(1, numbers_count):
            prefix_sum.append(prefix_sum[i - 1] + nums[i])
        # print(prefix_sum)
        return prefix_sum

    def sumRange(self, left: int, right: int) -> int:
        if left == 0:
            return self.prefix_sum[right]
        return self.prefix_sum[right] - self.prefix_sum[left - 1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)


if __name__ == '__main__':
    arr = NumArray([-2, 0, 3, -5, 2, -1])
    print(arr.sumRange(0, 2))
    print(arr.sumRange(2, 5))
    print(arr.sumRange(0, 5))
