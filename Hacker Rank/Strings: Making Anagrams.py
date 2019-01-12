if __name__ == '__main__':
    a = input()
    b = input()

    x = [0 for _ in range(26)]

    for i in a:
        x[ord(i)-ord('a')] += 1
    for i in b:
        x[ord(i)-ord('a')] -= 1

    s = 0
    for i in x:
        s += abs(i)

    print(s)

