from queue import LifoQueue
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False
        stack = LifoQueue()
        stack.put((root.val, root))
        while not stack.empty():
            total, node = stack.get()
            if total == targetSum and not node.left and not node.right:
                return True
            if node.left:
                stack.put((total + node.left.val, node.left))
            if node.right:
                stack.put((total + node.right.val, node.right))
        return False
