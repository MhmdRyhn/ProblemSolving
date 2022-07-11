from typing import List


class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        target = chr(ord("a") + (ord(target) - ord("a") + 1) % 26)
        if target > letters[-1]:
            return letters[0]
        start, end = 0, len(letters)
        while start < end:
            mid = (start + end) // 2
            if letters[mid] == target:
                return letters[mid]
            if letters[mid] < target:
                start = mid + 1
            else:
                end = mid
        return letters[start]


if __name__ == '__main__':
    assert Solution().nextGreatestLetter(["c", "f", "j"], "j") == "c"
    assert Solution().nextGreatestLetter(["c", "f", "j"], "z") == "c"
    assert Solution().nextGreatestLetter(["c", "f", "j"], "a") == "c"
    assert Solution().nextGreatestLetter(["c", "f", "j"], "c") == "f"
    print("All test case passed.")
