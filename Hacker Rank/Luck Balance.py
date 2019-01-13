# Category: Sorting, Greedy


if __name__ == '__main__':
    n, k = tuple(map(int, input().split()))

    zero, one = [], []
    zerol, onel = 0, 0

    for _ in range(n):
        a, b = tuple(map(int, input().split()))
        if b:
            one.append(a)
            onel += 1
        else:
            zero.append(a)
            zerol += 1

    one.sort(reverse=True)
    zero.sort(reverse=True)

    ans = 0

    for i in range(onel):
        if k:
            ans += one[i]
            k -= 1
        else:
            ans -= one[i]
    else:
        for j in range(zerol):
            ans += zero[j]

    print(ans)

