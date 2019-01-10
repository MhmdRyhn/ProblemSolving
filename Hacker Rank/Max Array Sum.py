# Category: Dynamic Programming


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    cnt = [0 for i in range(n)]
    
    if n >= 1:
        cnt[0] = arr[0]
    if n >= 2:
        cnt[1] = max(arr[0], arr[1])
    if n >= 3:
        cnt[2] = max([cnt[0], arr[0] + arr[2], arr[2]])
    if n > 3:
        for i in range(3, n):
            cnt[i] = max(
                max([cnt[i - 2], arr[i] + cnt[i - 2], arr[i]]),
                max([cnt[i - 3], arr[i] + cnt[i - 3], arr[i]])
            )

    print(max(cnt))

