# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import numpy as np


class Solution:
    # Runtime: 368 ms, faster than 9.53% of Python3 online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
    # Memory Usage: 32.6 MB, less than 88.89% of Python3 online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def helper(inorder, si, ei, postorder, sp, ep):
            if si > ei:
                return None
            root = TreeNode(postorder[ep])
            pos_i = np.where(np.array(inorder[si:(ei+1)]) == root.val)[0][0]
            n_l, n_r = pos_i, ei-si-pos_i
            root.left = helper(inorder, si, si+n_l-1, postorder, sp, sp+n_l-1)
            root.right = helper(inorder, si+pos_i+1, si +
                                pos_i+n_r, postorder, sp+pos_i, sp+pos_i+n_r-1)
            return root
        n = len(inorder)
        return helper(inorder, 0, n-1, postorder, 0, n-1)
