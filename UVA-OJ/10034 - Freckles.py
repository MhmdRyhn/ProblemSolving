from math import sqrt
from queue import PriorityQueue


class MST:
    def __init__(self, n, node):
        self.node = node
        self.n = n
        self.adj = {}
        self.visited = {}
        self.total = 0
        for i in range(n):
            self.visited[node[i]] = False
        self.create_graph()
        self.pq = PriorityQueue()

    def create_graph(self):
        for i in range(self.n):
            self.adj[self.node[i]] = []
            for j in range(self.n):
                if i != j:
                    self.adj[self.node[i]].append((self.dist(self.node[i], self.node[j]), self.node[j]))

    def dist(self, a, b):
        return sqrt(
            (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2
        )

    def insert_adjacent_of(self, u):
        for item in self.adj[u]:
            val, vertex = item[0], item[1]
            if not self.visited[vertex]:
                self.pq.put((val, vertex))

    def mst(self, source):
        self.visited[source] = True
        self.insert_adjacent_of(source)
        while not self.pq.empty():
            front = self.pq.get()
            val, vertex = front[0], front[1]

            if not self.visited[vertex]:
                self.total += val
                self.visited[vertex] = True
                self.insert_adjacent_of(vertex)
        return self.total


if __name__ == '__main__':
    t = int(input())

    for i in range(t):
        input()
        n = int(input())
        node = []
        for j in range(n):
            x = input().split()
            node.append((float(x[0]), float(x[1])))
        if i:
            print()
        print(round(MST(n, node).mst(node[0]), 2))

