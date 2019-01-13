# Category: Sorting, Greedy 


if __name__ == '__main__':
    n, k = tuple(map(int, input().split()))
    a = list(map(int, input().split()))

    a.sort(reverse=True)

    ans = 0

    for i in range(n):
        ans += a[i] * (int(i / k) + 1)

    print(ans)

