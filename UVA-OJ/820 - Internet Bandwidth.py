from queue import Queue
import math


class MaxFlow:
    def __init__(self, n, g):
        self.graph = g
        self.n = n
        self.parent = None

    def bfs(self, src, sink):
        self.parent = {}

        visited = [False]*self.n
        q = Queue()
        q.put(src)
        visited[src] = True

        while not q.empty():
            u = q.get()

            for index, val in enumerate(self.graph[u]):
                if val > 0 and not visited[index]:
                    q.put(index)
                    visited[index] = True
                    self.parent[index] = u
        return True if visited[sink] else False

    def ford_fulkerson(self, src, sink):
        max_flow = 0
        while self.bfs(src, sink):
            path_flow = math.inf

            s = sink
            while s != src:
                path_flow = min(
                    path_flow,
                    self.graph[self.parent[s]][s]
                )
                s = self.parent[s]
            max_flow += path_flow

            v = sink
            while v != src:
                u = self.parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = self.parent[v]

        return max_flow


if __name__ == '__main__':
    cnt = 1
    while True:
        node = int(input())
        if not node:
            break
        s, d, e = map(int, input().split())
        s, d = s-1, d-1
        g = [[0 for i in range(node)] for i in range(node)]

        for i in range(e):
            u, v, val = map(int, input().split())
            u, v = u-1, v-1
            g[u][v] += val
            g[v][u] += val

        print('Network', cnt)
        print('The bandwidth is '+str(MaxFlow(node, g).ford_fulkerson(s, d))+'.')
        print()
        cnt += 1

