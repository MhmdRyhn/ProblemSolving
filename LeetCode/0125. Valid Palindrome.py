class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = "".join(filter(str.isalnum, s)).lower()
        length = len(s)
        return s[0: length // 2] == s[-1: -length // 2 - (length % 2 + 1) % 2: -1]


if __name__ == '__main__':
    print(Solution().isPalindrome("a"))
    print(Solution().isPalindrome("ab"))
    print(Solution().isPalindrome("aba"))
    print(Solution().isPalindrome("acca"))
