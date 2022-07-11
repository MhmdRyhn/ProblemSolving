from queue import Queue
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        q = Queue()
        q.put((1, root))
        while not q.empty():
            level, node = q.get()
            if node.left is None and node.right is None:
                return level
            if node.left is not None:
                q.put((level + 1, node.left))
            if node.right is not None:
                q.put((level + 1, node.right))
