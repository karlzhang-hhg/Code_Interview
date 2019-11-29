# Method 1:
Iterative method. A dummy node is really helpful.

|Speed|Memory|
|---|---|
|98.15%|100.00%|


```python {.line-numbers}
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next, cnt, tmp = head, 1, dummy
        while cnt<m:
            cnt += 1
            tmp = tmp.next
        pre, cur, nnode= tmp, tmp.next, tmp.next.next
        while cnt<n:
            cnt +=1
            node, nnode = nnode, nnode.next
            node.next, cur = cur, node
        pre.next.next, pre.next = nnode, cur
        return dummy.next
```

# Method 2:
Recursive method. Think carefully about index.

|Speed|Memory|
|---|---|
|98.15%|100.00%|


```python {.line-numbers}
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        def helper(cur, pre, cnt):
            if cnt == 0:
                pre.next.next, pre.next = cur.next, cur
                return cur
            tmp = helper(cur.next, pre, cnt-1)
            tmp.next = cur
            return cur
        cnt, cur = 1, dummy
        while cnt<m:
            cnt+=1
            cur = cur.next
        helper(cur.next, cur, n-m)
        return dummy.next
```