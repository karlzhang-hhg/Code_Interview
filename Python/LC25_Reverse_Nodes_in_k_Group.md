# Method 1:
Recursive method. Follow the code in LC24.

|Speed|Memory|
|---|---|
|99.61%|47.06%|

```python {.line-numbers}
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        def helper(cur, pre, k):
            if not cur:
                return None
            
            if cur and k==1:
                pre.next.next, pre.next = cur.next, cur
                return cur
            
            tmp = helper(cur.next, pre, k-1)
            if tmp:
                tmp.next = cur
                return cur
            else:
                return None
        pre, cur = dummy, dummy.next
        while cur:
            cur = helper(cur, pre, k)
            if cur:
                pre, cur = cur, cur.next
        return dummy.next
```