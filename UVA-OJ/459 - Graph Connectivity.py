
element = None
par = None
rank = None

# f = None
#
#
# def of():
#     global f
#     f = open('/media/rayhan/CSE/MyCodes/OJs/uva/out.txt', 'w')


def init(elem):
    global element, par, rank
    element = elem
    par = None
    rank = None
    par = [i for i in range(element)]
    rank = [1 for i in range(element)]


def create_set(x):
    global element, par, rank
    par[x] = x
    rank[x] = 1
    

def merge_sets(x, y):
    global element, par, rank
    # x_root is the representative of x
    x_root = find_set(x)
    y_root = find_set(y)

    if x_root != y_root:
    
        # p = chr(x_root + ord('A'))
        # q = chr(y_root + ord('A'))
        # print('{} & {} are new PARENTS(before)'.format(p, q), file=f)
        # p = chr(x+ord('A'))
        # q = chr(y + ord('A'))
        # print('{}{} are new friends'.format(p, q), file=f)
        # print('Rank(before): {} {}'.format(rank[x_root], rank[y_root]), file=f)
        
        if rank[x_root] >= rank[y_root]:
            rank[x_root] += rank[y_root]
            par[y_root] = x_root
        else:
            rank[y_root] += rank[x_root]
            par[x_root] = y_root

        # p = chr(par[x] + ord('A'))
        # q = chr(par[x] + ord('A'))
        # print('{} & {} are new PARENTS(after)'.format(p, q), file=f)
        # print('Rank(after): {} {}'.format(rank[x_root], rank[y_root]), file=f)
        # print('ans: ', ans, file=f)

        return 1
    return 0


def find_set(x):
    global element, par, rank
    if par[x] != x:
        par[x] = find_set(par[x])
    return par[x]


def ser(p):
    return ord(p) - ord('A')


if __name__ == '__main__':
    # of()
    t = int(input())
    input()
    while t:
        a = input()
        n = ser(a[0]) + 1
        ans = n
        init(n)

        while True:
            try:
                a = input()
                if a == '':
                    break
            except EOFError:
                break

            ans -= merge_sets(ser(a[0]), ser(a[1]))

        print(ans)
        # print(ans, file=f)

        t -= 1
        if t:
            print()
    #         print(file=f)
    # f.close()
