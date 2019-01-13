Category: DP (Longest Common Subsequence, Straightforward)


def lcs(a, b, len_a, len_b):
    ans_board = [[0 for i in range(len_b + 1)] for j in range(len_a + 1)]

    for i in range(1, len_a + 1):
        for j in range(1, len_b + 1):
            if a[i - 1] == b[j - 1]:
                ans_board[i][j] = ans_board[i - 1][j - 1] + 1
            else:
                ans_board[i][j] = max(ans_board[i - 1][j], ans_board[i][j - 1])

    return ans_board[len_a][len_b]

if __name__ == '__main__':
    a = input()
    b = input()
    len_a, len_b = len(a), len(b)

    print(lcs(a, b, len_a, len_b))

