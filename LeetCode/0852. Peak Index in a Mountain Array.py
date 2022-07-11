from typing import List


class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        size = len(arr)
        start, end = 0, size
        while start < end:
            mid = (start + end) // 2
            if arr[mid - 1] < arr[mid] and arr[mid] > arr[mid + 1]:
                return mid
            if arr[mid - 1] < arr[mid] < arr[mid + 1]:
                start = mid
            else:
                end = mid
        return start


if __name__ == '__main__':
    assert Solution().peakIndexInMountainArray([4, 5, 3]) == 1
    assert Solution().peakIndexInMountainArray([4, 5, 3, 2]) == 1
    assert Solution().peakIndexInMountainArray([5, 6, 7, 8, 9, 1]) == 4
    assert Solution().peakIndexInMountainArray([5, 6, 7, 8, 9, 1]) == 4
    assert Solution().peakIndexInMountainArray([4, 6, 4, 3, 2, 1, 0]) == 1
    print("All test case passed.")
