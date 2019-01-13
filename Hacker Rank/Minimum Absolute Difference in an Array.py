# Category: Sorting, Greedy, Brute force


if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))

    arr.sort()

    m = 10 ** 10
    for i in range(1, n):
        m = min(m, abs(arr[i - 1] - arr[i]))
    print(m)

