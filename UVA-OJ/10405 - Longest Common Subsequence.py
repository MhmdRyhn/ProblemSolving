
dp = None


def lcs(s1, s2, m, n):
    for i in range(0, m+1):
        for j in range(0, n+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[m][n]


if __name__ == '__main__':
    while True:
        try:
            s1 = input()
            s2 = input()

            m, n = len(s1), len(s2)
            dp = [[0 for i in range(n + 1)] for j in range(m + 1)]
            ans = lcs(s1, s2, m, n)
            print(ans)
        except:
            break


