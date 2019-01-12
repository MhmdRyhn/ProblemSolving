if __name__ == '__main__':
    q = int(input())
    for _ in range(q):
        s = input()
        l = len(s)
        c = 0
        for i in range(1, l):
            if s[i] == s[i - 1]:
                c += 1
        print(c)

