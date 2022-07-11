from queue import Queue
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not p or not q:
            return False
        dual_q = Queue()
        dual_q.put((p, q))
        while not dual_q.empty():
            p_node, q_node = dual_q.get()
            if p_node.val != q_node.val:
                return False
            if p_node.left and q_node.left:
                dual_q.put((p_node.left, q_node.left))
            elif p_node.left or q_node.left:
                return False
            if p_node.right and q_node.right:
                dual_q.put((p_node.right, q_node.right))
            elif p_node.right or q_node.right:
                return False
        return True
