class DisjointSet:
    def __init__(self, n, data):
        self.graph = data
        self.n = n
        self.parent = [i for i in range(self.n)]
        self.rank = [1] * self.n

    def find_parent(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find_parent(self.parent[x])
        return self.parent[x]

    def merge_sets(self, x, y):
        p_x = self.find_parent(x)
        p_y = self.find_parent(y)

        if p_x == p_y:
            return False

        if self.rank[p_x] >= self.rank[p_y]:
            self.rank[p_x] += self.rank[p_y]
            self.parent[p_y] = p_x
            self.rank[p_y] = 0
        else:
            self.rank[p_y] += self.rank[p_x]
            self.parent[p_x] = p_y
            self.rank[p_x] = 0
        return True


class MST(DisjointSet):
    def __init__(self, n, data):
        super().__init__(n, data)
        self.result = []

    def kruskal(self):
        self.graph = sorted(self.graph, key=lambda e: e[0])
        for item in self.graph:
            # w = item[0]
            # u = item[1]
            # v = item[2]
            w, u, v = item
            if not self.merge_sets(u, v):
                self.result.append(w)
        return self.result


if __name__ == '__main__':
    while True:
        try:
            n, m = map(int, input().split())
            if n + m:
                g = []
                for i in range(m):
                    u, v, w = map(int, input().split())
                    g.append((w, u, v))
                ans = MST(n, g).kruskal()
                sz = len(ans)
                if sz:
                    print(*ans)
                else:
                    print('forest')
            else:
                break
        except Exception as e:
            break

