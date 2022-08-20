from queue import LifoQueue


class Solution:
    def isValid(self, s: str) -> bool:
        pair = {"(": ")", "{": "}", "[": "]"}
        stack = LifoQueue()
        for char in s:
            if char in pair:
                stack.put(char)
            elif stack.empty() or pair[stack.get()] != char:
                return False
        return stack.empty()


if __name__ == '__main__':
    print(Solution().isValid("(([{}([])]))"))
    print(Solution().isValid("(([{"))
