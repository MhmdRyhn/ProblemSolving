import queue
from collections import defaultdict
from statistics import mean
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        if root is None:
            return []
        q = queue.Queue()
        q.put((0, root))
        dd = defaultdict(list)
        dd[0].append(root.val)
        while not q.empty():
            level, node = q.get()
            dd[level].append(node.val)
            if node.left:
                q.put((level + 1, node.left))
            if node.right:
                q.put((level + 1, node.right))
        ans = []
        for _, value in dd.items():
            ans.append(mean(value))
        return ans
