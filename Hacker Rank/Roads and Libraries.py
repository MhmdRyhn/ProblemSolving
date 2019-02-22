# The commented code below fails for case#4
# If you can explain the reason, then do it


class DisjointSet:
    def __init__(self, element):
        self.element = element
        self.parent = [i for i in range(element)]
        self.rank = [1 for _ in range(element)]

    def find_parent(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find_parent(self.parent[x])
        return self.parent[x]

    def merge_sets(self, x, y):
        x_root = self.find_parent(x)
        y_root = self.find_parent(y)

        if x_root == y_root:
            return False

        if self.rank[x_root] >= self.rank[y_root]:
            self.rank[x_root] += self.rank[y_root]
            self.parent[y_root] = x_root
            self.rank[y_root] = 0
        else:
            self.rank[y_root] += self.rank[x_root]
            self.parent[x_root] = y_root
            self.rank[x_root] = 0
        return True

    def get_positive_ranks(self):
        return [self.rank[i] for i in range(self.element) if self.rank[i]]


if __name__ == '__main__':
    q = int(input())
    for i in range(q):
        n, e, cl, cr = tuple(map(int, input().split()))

        if cr >= cl:
            print(n * cl)
        else:
            ds = DisjointSet(n)

        for _ in range(e):
            a, b = tuple(map(int, input().split()))
            if cr >= cl:
                continue
            ds.merge_sets(a - 1, b - 1)

        if cr >= cl:
            continue
        elem = ds.get_positive_ranks()

        total = 0
        for x in elem:
            total += (x - 1) * cr + cl
        print(total)


"""
from queue import Queue


def bfs_dis(graph, n, lib_cost, road_cost):
    if road_cost >= lib_cost:
        return n * lib_cost
    total = 0
    visited = [False for _ in range(n)]
    for i in range(n):
        if not visited[i]:
            q = Queue()
            q.put(i)
            visited[i] = True
            cnt = 1
            while not q.empty():
                u = q.get()
                adj = graph[u]
                for v in adj:
                    if not visited[v]:
                        q.put(v)
                        visited[v] = True
                        cnt += 1
            total += road_cost * (cnt - 1) + lib_cost
    return total


if __name__ == '__main__':
    q = int(input())
    for i in range(q):
        n, e, cl, cr = tuple(map(int, input().split()))

        # graph = {k: [] for k in range(1, n + 1)}
        graph = [[] for i in range(n)]

        for i in range(e):
            a, b = tuple(map(int, input().split()))
            graph[a - 1].append(b - 1)
            graph[b - 1].append(a - 1)
        ans = bfs_dis(graph, n, cl, cr)
        print(ans)

"""

