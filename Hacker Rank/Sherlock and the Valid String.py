if __name__ == '__main__':
    a = input()
    s = set()

    d = [0 for _ in range(26)]
    for i in a:
        d[ord(i) - ord('a')] += 1

    y = []
    for i in d:
        if i:
            y.append(i)

    n = len(y)

    flag = False
    othernum = y[0]

    for i in range(n):
        c = 0
        for j in range(n):
            if y[i] == y[j]:
                c += 1
            else:
                othernum = y[j]
        if c == n:
            print('YES')
            flag = True
            break
        if c == (n - 1):
            if othernum == 1 or othernum == (y[i - 1] + 1):
                print('YES')
            else:
                print('NO')
            flag = True
            break
        if flag:
            break
    else:
        print('NO')

