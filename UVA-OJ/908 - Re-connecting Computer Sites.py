class DisjointSet:
    def __init__(self, n, data):
        self.n = n
        self.graph = data
        self.parent = [i for i in range(self.n + 1)]
        self.rank = [1] * (self.n + 1)

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
        self.total = 0

    def kruskal(self):
        self.graph = sorted(self.graph, key=lambda e: e[0])
        cnt = 0
        for item in self.graph:
            w, u, v = item
            if self.merge_sets(u, v):
                self.total += w
                cnt += 1
            if cnt == (self.n - 1):
                return self.total
        return self.total


if __name__ == '__main__':
    t = 0
    while True:
        g = []
        total = 0
        try:
            if t:
                x = input()
            n = int(input())

            for i in range(n - 1):
                u, v, w = map(int, input().split())
                total += w
                g.append((w, u, v))

            if t:
                print()
            print(total)  # prints o/p

            k = int(input())
            for i in range(k):
                u, v, w = map(int, input().split())
                g.append((w, u, v))

            # Basically this Input set is useless.
            # Because, previously selected (n-1)
            # edges've been selected from this m edges.
            m = int(input())
            for i in range(m):
                u, v, w = map(int, input().split())

            print(MST(n, g).kruskal())  # prints o/p

            t = 1
        except Exception as e:
            break

