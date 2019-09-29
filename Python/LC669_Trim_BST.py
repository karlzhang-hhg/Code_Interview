# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # Definition of BST should require no duplicated tree values.
    # Runtime: 52 ms, faster than 94.01% of Python3 online submissions for Trim a Binary Search Tree.
    # Memory Usage: 17.9 MB, less than 7.14% of Python3 online submissions for Trim a Binary Search Tree. (The solution use the same memory)
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        # def trimBSTHelper(root, L, R):
        #     if root == None:
        #         return root
        #     if root.val < L:
        #         return trimBSTHelper(root.right, L, R)
        #     elif root.val > R:
        #         return trimBSTHelper(root.left, L, R)
        #     else:
        #         root.left = trimBSTHelper(root.left, L, root.val)
        #         root.right = trimBSTHelper(root.right, root.val, R)
        #         return root

        def trimBSTHelper(root, L, R):
            if root == None:
                return root
            if root.val < L:
                return trimBSTHelper(root.right, L, R)
            elif root.val > R:
                return trimBSTHelper(root.left, L, R)
            else:
                root.left = trimBSTHelper(root.left, L, root.val)
                root.right = trimBSTHelper(root.right, root.val, R)
                return root

        return trimBSTHelper(root, L, R)
