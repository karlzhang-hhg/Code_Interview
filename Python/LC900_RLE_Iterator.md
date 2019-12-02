# Method 1:
This problem is similar to LC604, but it has significant difference. Be careful about the requirements. 

|Speed|Memory|
|---|---|
|97.38%|100.00%|

```python {.line-numbers}
class RLEIterator:

    def __init__(self, A: List[int]):
        self.ls = A
        self.num = -1
        self.idx = 0
        self.size = 0
        self.cnt = 0
        
    def next(self, n) -> int:
        while self.cnt<self.size or self.idx < len(self.ls):
            if self.cnt==self.size:
                self.size = self.ls[self.idx]
                self.idx += 1
                self.num = self.ls[self.idx]
                self.idx += 1
                self.cnt = 0
            if n>self.size-self.cnt:
                n -= self.size-self.cnt
                self.cnt = self.size
            else:
                self.cnt += n
                return self.num
        return -1


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)
```