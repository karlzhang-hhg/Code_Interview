"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
# Runtime: 44 ms, faster than 83.91% of Python3 online submissions for Copy List with Random Pointer.
# Memory Usage: 14.7 MB, less than 100.00% of Python3 online submissions for Copy List with Random Pointer.
# O(n)

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head is None:
            return None
        cur = head
        cp = cp_head = Node(head.val, None, None)
        vn = {cp_head.val: cp_head}
        while cur.next is not None:
            cur = cur.next
            cp.next = Node(cur.val, None, None)
            vn[cur.val] = cp.next
            cp = cp.next
        cp, cur = cp_head, head
        while cp is not None:
            if cur.random is not None: # This could be a bug
                cp.random = vn[cur.random.val]
            cp, cur = cp.next, cur.next
        return cp_head