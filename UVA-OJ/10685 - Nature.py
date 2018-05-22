class DisjointSet:
    element = None
    par = None
    rank = None

    def __init__(self):
        self.par = {}
        self.rank = {}

    def create_set(self, x):
        self.par[x] = x
        self.rank[x] = 1

    def merge_sets(self, x, y):
        x_root = self.find_set(x)
        y_root = self.find_set(y)

        if x_root == y_root:
            return False

        if self.rank[x_root] >= self.rank[y_root]:
            self.rank[x_root] += self.rank[y_root]
            self.par[y_root] = x_root
            self.rank[y_root] = 0
        else:
            self.rank[y_root] += self.rank[x_root]
            self.par[x_root] = y_root
            self.rank[x_root] = 0

        return True

    def find_set(self, x):
        if self.par[x] == x:
            return self.par[x]

        self.par[x] = self.find_set(self.par[x])
        return self.par[x]

    def get_long(self):
        mx = 0
        for i in self.rank.values():
            mx = max(mx, i)
        return mx


if __name__ == '__main__':
    while True:
        n, r = map(int, input().split())
        if not n and not r:
            break

        ds = DisjointSet()

        for i in range(n):
            a = input()
            ds.create_set(a)

        for i in range(r):
            a, b = input().split()
            ds.merge_sets(a, b)

        print(ds.get_long())
        input()
