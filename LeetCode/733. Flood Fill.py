from copy import deepcopy
from queue import Queue
from typing import List


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if color == image[sr][sc]:
            return image
        rows_count = len(image)
        columns_count = len(image[0])
        src_color = deepcopy(image[sr][sc])
        q = Queue()
        q.put((sr, sc))
        image[sr][sc] = color
        four_directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while not q.empty():
            top = q.get()
            row, column = top
            for direction in four_directions:
                dirx, diry = direction
                if 0 <= (row + dirx) < rows_count and 0 <= (column + diry) < columns_count \
                    and image[row + dirx][column + diry] == src_color:
                    q.put((row + dirx, column + diry))
                    image[row + dirx][column + diry] = color
        return image


if __name__ == "__main__":
    image = [[1,1,1],[1,1,0],[1,0,1]]
    sr = 1
    sc = 1
    color = 2
    ans = Solution().floodFill(image, sr, sc, color)
    for row in ans:
        print(row)
