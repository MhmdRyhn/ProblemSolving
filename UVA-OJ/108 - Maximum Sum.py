def max_sum_subarray_1D(arr, sz):
    cur_max_sum = global_max_sum = arr[0]

    for i in range(1, sz):
        cur_max_sum = max(arr[i], cur_max_sum+arr[i])
        if cur_max_sum > global_max_sum:
            global_max_sum = cur_max_sum

    return global_max_sum


def max_sum_subarray_2D(arr_2d, m, n):
    for i in range(m):
        for j in range(1, n):
            arr_2d[i][j] += arr_2d[i][j-1]

    cur_sum, max_sum = 0, 0

    for l in range(n):
        for r in range(l, n):
            arr = []
            for k in range(m):
                if l != 0:
                    arr.append(arr_2d[k][r] - arr_2d[k][l-1])
                else:
                    arr.append(arr_2d[k][r])

            cur_sum = max_sum_subarray_1D(arr, m)
            if cur_sum > max_sum:
                max_sum = cur_sum

    return max_sum


if __name__ == '__main__':
    while True:
        try:
            n = int(input())
        except EOFError:
            break
        arr = [[0 for i in range(n)] for j in range(n)]
        i, j = 0, 0
        while True:
            a = None
            try:
                a = list(map(int, input().split()))
            except EOFError:
                break

            sz = len(a)

            for k in range(sz):
                if j < n:
                    arr[i][j] = a[k]
                    j += 1
                else:
                    j = 0
                    i += 1
                    arr[i][j] = a[k]
                    j += 1

                if i > (n-1) and j > (n-1):
                    break

            if i == (n - 1) and j > (n - 1):
                break

        ans = max_sum_subarray_2D(arr, n, n)
        print(ans)


