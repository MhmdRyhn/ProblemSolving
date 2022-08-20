from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.swap_children_nodes(root)
        return root

    def swap_children_nodes(self, root: Optional[TreeNode]):
        if root is None:
            return
        root.left, root.right = root.right, root.left
        self.swap_children_nodes(root.left)
        self.swap_children_nodes(root.right)
