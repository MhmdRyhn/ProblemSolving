def f(x, m):
    d = {}
    l = len(x)
    for k in range(l):
        if not x[k] in d:
            if (m - x[k]) in d:
                return d[m - x[k]], k + 1
            else:
                d[x[k]] = k + 1
        elif 2 * x[k] == m:
            return d[x[k]], k + 1


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        m = int(input())
        n = int(input())
        x = list(map(int, input().split()))
        print(*f(x, m))

