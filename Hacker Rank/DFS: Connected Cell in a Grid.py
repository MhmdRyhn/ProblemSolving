from queue import Queue


def bfs(grid, row, column):
    unvisited = {(ro, col): 1 for ro in range(row) for col in range(column) if grid[ro][col]}
    dir = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    mx = 0
    while unvisited:
        start = unvisited.popitem()
        q = Queue()
        q.put(start[0])
        cnt = 1
        while not q.empty():
            u = q.get()
            for a, b in dir:
                r, c = a + u[0], b + u[1]
                if r >= 0 and c >= 0 and unvisited.get((r, c)):
                    cnt += 1
                    q.put((r, c))
                    unvisited.pop((r, c))
        mx = max(mx, cnt)
    return mx


if __name__ == '__main__':
    r = int(input())
    c = int(input())

    grid = [list(map(int, input().split())) for _ in range(r)]

    ans = bfs(grid, r, c)
    print(ans)

