from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        return [self.count_bit_in_a_number(i) for i in range(n + 1)]

    def count_bit_in_a_number(self, number):
        bits_count = 0
        while number:
            bits_count += number % 2
            number //= 2
        return bits_count


class SolutionDP:
    def countBits(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        ans = [0]
        for i in range(1, n + 1):
            ans.append(ans[i // 2] + i % 2)
        return ans


if __name__ == '__main__':
    # print(Solution().countBits(5))
    print(SolutionDP().countBits(5))
