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
            return self.rank[x_root]

        if self.rank[x_root] >= self.rank[y_root]:
            self.rank[x_root] += self.rank[y_root]
            self.par[y_root] = x_root
            self.rank[y_root] = 0
            return self.rank[x_root]
        else:
            self.rank[y_root] += self.rank[x_root]
            self.par[x_root] = y_root
            self.rank[x_root] = 0
            return self.rank[y_root]

    def find_set(self, x):
        if self.par[x] == x:
            return self.par[x]

        self.par[x] = self.find_set(self.par[x])
        return self.par[x]

    def is_in_set(self, x):
        if x in self.par.keys():
            return True
        return False


if __name__ == '__main__':
    t = int(input())
    while t:
        n = int(input())

        ds = DisjointSet()

        for i in range(n):
            a, b = input().split()
            if not ds.is_in_set(a):
                ds.create_set(a)
            if not ds.is_in_set(b):
                ds.create_set(b)
            print(ds.merge_sets(a, b))

        t -= 1

