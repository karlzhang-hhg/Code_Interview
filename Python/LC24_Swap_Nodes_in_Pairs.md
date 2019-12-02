# Method 1:
Iterative method.

|Speed|Memory|
|---|---|
|97.63%|100.00%|

```python {.line-numbers}
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        cur = dummy
        while cur.next and cur.next.next:
            nnode, tail = cur.next.next.next, cur.next.next
            cur.next.next.next, cur.next.next, cur.next = cur.next, nnode, tail
            cur = cur.next.next # This line cannot be put with the previous line using structure binding, o.w. it would be wrong.
        return dummy.next
```


# Method 2:

|Speed|Memory|
|---|---|
|97.63%|100.00%|

```python {.line-numbers}
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        def helper(cur, pre, k):
            # This can be used to do k-Group reverse, LC25
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
        pre, cur, k = dummy, dummy.next, 2
        while cur:
            cur = helper(cur, pre, k)
            if cur:
                pre, cur = cur, cur.next
        return dummy.next
```