# Category: Sorting, Greedy 


if __name__ == '__main__':
    n = int(input())
    k = int(input())

    arr = []
    for _ in range(n):
        a = int(input())
        arr.append(a)

    arr.sort()
    ans = arr[n - 1]

    to = n - k + 1
    for i in range(to):
        ans = min(ans, arr[i + k - 1] - arr[i])

    print(ans)

