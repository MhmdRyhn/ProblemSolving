from math import sqrt


class DisjointSet:
    def __init__(self, n, node):
        self.parent = [None] * n
        self.rank = [None] * n
        self.create_set(node)

    def create_set(self, node):
        sz = len(node)
        for item in range(sz):
            self.parent[item] = item
            self.rank[item] = 1

    def find_parent(self, item):
        if self.parent[item] != item:
            self.parent[item] = self.find_parent(self.parent[item])
        return self.parent[item]

    def is_same_set(self, x, y):
        p_x = self.find_parent(x)
        p_y = self.find_parent(y)

        if p_x == p_y:
            return True

        if self.rank[p_x] >= self.rank[p_y]:
            self.parent[p_y] = p_x
            self.rank[p_x] += self.rank[p_y]
            self.rank[p_y] = 0
        else:
            self.parent[p_x] = p_y
            self.rank[p_y] += self.rank[p_x]
            self.rank[p_x] = 0
        return False


class MST(DisjointSet):
    def __init__(self, n, r, node):
        super().__init__(n, node)
        self.n = n
        self.r = r
        self.node = node
        self.graph = []
        self.create_graph()

    def distance(self, a, b):
        return sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)

    def create_graph(self):
        for i in range(self.n):
            for j in range(i + 1, self.n):
                self.graph.append((self.distance(self.node[i], self.node[j]), i, j))

    def kruskal(self):
        self.graph = sorted(self.graph, key=lambda e: e[0])
        ct = 0
        road = 0
        rail = 0

        for item in self.graph:
            d = item[0]
            u = item[1]
            v = item[2]

            if not self.is_same_set(u, v):
                if d <= r:
                    ct += 1
                    road += d
                else:
                    rail += d
                if ct == (self.n - 1):
                    break
        state = self.n - ct
        return state, round(road), round(rail)


if __name__ == '__main__':
    try:
        t = int(input())

        for i in range(t):
            n, r = (map(int, input().split()))

            node = []
            for j in range(n):
                x, y = (map(int, input().split()))
                node.append((x, y))

            ans = MST(n, r, node).kruskal()
            print('Case #{0}: {1} {2} {3}'.format(i + 1, ans[0], ans[1], ans[2]))
    except Exception:
        pass

