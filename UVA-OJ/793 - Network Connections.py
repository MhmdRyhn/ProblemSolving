class DisjointSet:
    element = None
    par = None
    rank = None

    def __init__(self, element):
        self.par = [i for i in range(element+1)]
        self.rank = [1 for i in range(element+1)]

    def merge_sets(self, x, y):
        x_root = self.find_set(x)
        y_root = self.find_set(y)

        if x_root == y_root:
            return self.rank[x_root]

        if self.rank[x_root] >= self.rank[y_root]:
            self.rank[x_root] += self.rank[y_root]
            self.par[y_root] = x_root
            self.rank[y_root] = 0
        else:
            self.rank[y_root] += self.rank[x_root]
            self.par[x_root] = y_root
            self.rank[x_root] = 0

    def find_set(self, x):
        if self.par[x] == x:
            return self.par[x]

        self.par[x] = self.find_set(self.par[x])
        return self.par[x]

    def is_same_set(self, x, y):
        if self.find_set(x) == self.find_set(y):
            return True
        return False


if __name__ == '__main__':
    t = int(input())
    input()
    for i in range(0, t):
        a, b, x, l = None, None, None, None
        correct, incorrect = 0, 0
        n = int(input())
        ds = DisjointSet(n)
        while True:
            try:
                l = input()
                if l != '':
                    x, a, b = l.split()
                    a, b = int(a), int(b)
                else:
                    break
            except EOFError:
                break

            if x == 'c':
                ds.merge_sets(a, b)
            else:
                if ds.find_set(a) == ds.find_set(b):
                    correct += 1
                else:
                    incorrect += 1

        if i:
            print()
        print('{},{}'.format(correct, incorrect))
