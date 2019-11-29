# Method 1:
Iterative method.

|Speed|Memory|
|---|---|
|98.29%|100.00%|

```python {.line-numbers}
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        nnode, head.next, cur = head.next, None, head
        while nnode is not None:
            tmp, nnode = nnode, nnode.next
            tmp.next, cur = cur, tmp
        return cur
```

# Method 2:
Recursive method.

|Speed|Memory|
|---|---|
|98.29%|22.73%|

```python {.line-numbers}
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # if not head:
        #     return head
        # def helper(head):
        #     if not head.next:
        #         return head, head
        #     tmp, tail = helper(head.next)
        #     head.next, tail.next = None, head
        #     return tmp, head
        # head, _ = helper(head)
        # return head
        if (not head) or (not head.next): return head
        tmp = self.reverseList(head.next)
        head.next.next, head.next = head, None # The order matters in this structure binding
        return tmp
```