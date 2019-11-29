# Method 1:
I wrapped the Node into List. This way I can track the count of usage frequency and time it is lastly used in List. This way, `.get` and `.put` are all in O(1). There could be some improvement in speed and memory.

|Speed|Memory|
|---|---|
|52.61%|50.00%|

```python {.line-numbers}
class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.cnt = 0
        self.pre = None
        self.next = None
        
class List:
    def __init__(self, cnt=0):
        self.cnt = cnt
        self.size = 0
        self.head = Node(0, -1)
        self.tail = Node(0, -1)
        self.head.next, self.tail.pre = self.tail, self.head
        self.pre, self.next = None, None
    
    def insert(self, node):
        node.next, node.pre = self.head.next, self.head
        node.next.pre, self.head.next = node, node
        self.size += 1
        
    def delete_last(self):
        node = self.tail.pre
        self.delete(node)
        return node
    
    def delete(self, node):
        node.pre.next, node.next.pre = node.next, node.pre
        node.pre, node.next = None, None
        self.size -= 1

    
class LFUCache():

    def __init__(self, capacity: int):
        self.head, self.tail = List(-1), List(-1) # dummy List
        self.head.next, self.tail.pre = self.tail, self.head
        self.map = {} # map the key to the list and node
        self.cap = capacity
        self.size = 0
        
    def insert(self, lst, pre_lst):
        lst.next, lst.pre = pre_lst.next, pre_lst
        lst.next.pre, pre_lst.next = lst, lst
    
    def delete(self, lst):
        lst.pre.next, lst.next.pre = lst.next, lst.pre
        lst.pre, lst.next = None, None
        del lst
        
    def update_cnt(self, key):
        lst, node = self.map[key]
        node.cnt += 1
        lst.delete(node)
        if lst.pre.cnt!=node.cnt: # don't use > because it could be dummy head
            # create a new List
            tmp_lst = List(node.cnt)
            self.insert(tmp_lst, lst.pre)
        else:
            tmp_lst = lst.pre
        tmp_lst.insert(node)
        if lst.size==0:
            self.delete(lst)
        self.map[key] = [tmp_lst, node]
        
    def get(self, key: int) -> int:
        res = -1
        if key in self.map:
            _, node = self.map[key]
            res = node.val
            self.update_cnt(key)
        return res

    def put(self, key: int, value: int) -> None:
        if self.cap == 0:
            return
        if key in self.map:
            _, node = self.map[key]
            node.val = value
            self.update_cnt(key)
        else:
            if self.size == self.cap:
                lst = self.tail.pre
                node = lst.delete_last()
                self.map.pop(node.key, None)
                node.key, node.val, node.cnt = key, value, 0
                if lst.size == 0:
                    self.delete(lst)
            else:
                node = Node(key, value)
                self.size += 1
            if self.tail.pre.cnt == 0:
                lst = self.tail.pre
            else:
                lst = List(0)
                self.insert(lst, self.tail.pre)
            lst.insert(node)
            self.map[key] = [lst, node]


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```

# Method 2:
I don't need to build a List to store nodes. I can use a double-linked list to store the head and tail of each count of usage frequency. This can be smaller and faster, but the code can be more complex.