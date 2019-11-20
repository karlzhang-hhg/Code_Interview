"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
# Runtime: 376 ms, faster than 96.58% of Python3 online submissions for Populating Next Right Pointers in Each Node II.
# Memory Usage: 49.6 MB, less than 8.33% of Python3 online submissions for Populating Next Right Pointers in Each Node II.
# Recursive

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root
        
        p, nn=root, None
        while p.next:
            p = p.next
            if p.left:
                nn=p.left
                break
            if p.right:
                nn=p.right
                break
        if root.right:
            root.right.next = nn
            self.connect(root.right)
            nn=root.right
        if root.left:
            root.left.next = nn
            self.connect(root.left)
        return root

# Runtime: 384 ms, faster than 88.68% of Python3 online submissions for Populating Next Right Pointers in Each Node II.
# Memory Usage: 49.6 MB, less than 8.33% of Python3 online submissions for Populating Next Right Pointers in Each Node II.
# Iterative

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        dummy = Node(-1, None, None, None)
        p = root
        cur = dummy
        while True:
            while p:
                if p.left:
                    cur.next = p.left
                    cur=cur.next
                if p.right:
                    cur.next = p.right
                    cur=cur.next
                p=p.next
            if not dummy.next:
                return root
            else:
                p = dummy.next
                cur = dummy
                dummy.next = None