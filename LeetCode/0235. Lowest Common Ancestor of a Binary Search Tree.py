# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val > q.val:
            p, q = q, p
        return self.find_lca(root, p, q)

    def find_lca(self, root: TreeNode, p: TreeNode, q: TreeNode):
        """ Pass p, q so that `p.val` is less than `q.val` """
        if root.val in [p.val, q.val] or p.val < root.val < q.val:
            return root
        if q.val < root.val:
            return self.find_lca(root.left, p, q)
        return self.find_lca(root.right, p, q)
