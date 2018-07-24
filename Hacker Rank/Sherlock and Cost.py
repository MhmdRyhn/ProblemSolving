# We notice picking a number in between doesn't make sense.
# That is, for every A_i, it either equal to 1 or B_i.
# We use dp[i][j] = k to denote, the first i elements will have largest cost = k, with A[i] = (j==0?1:B[i]).
# Here j is a state variable. We use j=0 denote A[i] = 1, and j=1 denote A[i] = B[i].


if __name__ == '__main__':
    t = int(input())
    for x in range(t):
        n = int(input())
        b = list(map(int, input().split()))

        dp = [[0, 0] for i in range(n+5)]

        for i in range(1, n):
            dp[i][0] = max(dp[i-1][0] + (1-1), dp[i-1][1] + (b[i-1]-1))
            dp[i][1] = max(dp[i-1][0] + (b[i]-1), dp[i-1][1] + abs(b[i]-b[i-1]))

        ans = max(dp[n-1][0], dp[n-1][1])
        print(ans)


