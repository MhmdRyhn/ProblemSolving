from queue import Queue
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        max_depth = 1
        q = Queue()
        q.put((max_depth, root))
        while not q.empty():
            max_depth, node = q.get()
            if node.left:
                q.put((max_depth + 1, node.left))
            if node.right:
                q.put((max_depth + 1, node.right))
        return max_depth
