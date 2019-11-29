# Method 1:
This problem requires O(1) `.get(key)`, so that we need dictionary for sure. We also need to maintain and find the time order of keys that is accessed. When we use `.get` and `.put` methods, we are doing random accessing. We also need to move to the end of container. The only way to keep O(1) time is using linked list. Because I need to find a node and delete a node in O(1) time, I need to use double-linked list, so that it easier to code.

There are some tricks:
- Use two dummy nodes for head and tail so that I don't need to check if they are `None` or not.
- Write a method `.move_top`, because `.get` and `.put` methods both need it.

|Speed|Memory|
|---|---|
|80.54%|6.06%|

```python {.line-numbers}
class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.pre = None
            
class LRUCache:
    def __init__(self, capacity: int):
        self.head = Node(0, -1) # head
        self.tail = Node(0, -1) # tail
        self.head.next, self.tail.pre = self.tail, self.head
        self.cap = capacity
        self.size = 0
        self.map = {} # key: pre-node

    def move_top(self, node):
        node.pre.next, node.next.pre = node.next, node.pre
        node.next, node.pre = self.head.next, self.head
        node.next.pre, self.head.next = node, node
            
    def get(self, key: int) -> int:
        res = -1
        if key in self.map:
            node = self.map[key]
            res = node.val
            self.move_top(node)
        return res

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            node = self.map[key]
            node.val = value
            self.move_top(node)
        else:
            if self.size == self.cap:
                node = self.tail.pre
                self.map.pop(node.key, None)
                node.key, node.val = key, value
                self.move_top(node)
            else:
                node = Node(key, value)
                self.size += 1
                node.next, node.pre = self.head.next, self.head
                node.next.pre, self.head.next = node, node
            self.map[key] = node
            
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```

# Method 2:
This method is cleaner, because we are using the built-in container `OrderedDict`. It keeps the order that a key is inserted in the dictionary like container.

|Speed|Memory|
|---|---|
|96.64%|42.42%|            
                
```python {.line-numbers}
from collections import OrderedDict
class LRUCache(OrderedDict):
    def __init__(self, capacity: int):
        self.cap = capacity
            
    def get(self, key: int) -> int:
        res = -1
        if key in self:
            res = self[key]
            self.move_to_end(key)
        return res

    def put(self, key: int, value: int) -> None:
        if key in self:
            self.move_to_end(key) # O(1) operation
        else:
            if len(self) == self.cap:
                self.popitem(last=False)
        self[key] = value

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```
            
            


