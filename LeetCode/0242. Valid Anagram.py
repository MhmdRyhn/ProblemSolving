import collections


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        counter = collections.defaultdict(int)
        for char in s:
            counter[char] += 1
        for char in t:
            counter[char] -= 1
        return all(c == 0 for c in counter.values())


if __name__ == '__main__':
    pass
