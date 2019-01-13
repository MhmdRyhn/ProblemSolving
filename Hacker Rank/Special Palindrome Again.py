# Categort: Constructive algorithm 
# Time Complexity: O(n)


if __name__ == '__main__':
    n = int(input())
    s = input()
    s += 'X'

    cnt = [[0, 0] for _ in range(n)]
    c = 1
    ans = 0

    for i in range(1, n + 1):
        if s[i] == s[i - 1]:
            c += 1
        else:
            ans += (c * (c - 1)) / 2
            cnt[i - c][0] = c
            cnt[i - 1][1] = c
            c = 1

    for i in range(1, n - 1):
        if cnt[i][0] == 1 and s[i - 1] == s[i + 1]:
            ans += min(cnt[i - 1][1], cnt[i + 1][0])

    print(int(ans) + n)

