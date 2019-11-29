# Method 1:
This problem is not that easy. In order to write it clean, I need to decide what state I want to keep track of to write `.next` method. I decide to keep the current character, the size of if and the current count that it is already displayed. Then, I need to decide how to initialize those instance variables. I decide to use the condition that `self.size == self.cnt` as condition that whether I want to find the next letter and corresponding count. This makes the code clean and simple.

|Speed|Memory|
|---|---|
|92.27%|100.00%|

```python {.line-numbers}
class StringIterator:

    def __init__(self, compressedString: str):
        self.comp_str = compressedString
        self.char = None
        self.idx = 0
        self.size = 0
        self.cnt = 0
        self.num_str = list("0123456789")

    def next(self) -> str:
        if self.size==self.cnt:
            if self.idx == len(self.comp_str):
                return " "
            self.char = self.comp_str[self.idx]
            self.idx += 1
            tmp_idx = self.idx
            while self.idx<len(self.comp_str) and self.comp_str[self.idx] in self.num_str:
                self.idx += 1
            self.size = int(self.comp_str[tmp_idx:self.idx])
            self.cnt = 0
        self.cnt += 1
        return self.char
                
    def hasNext(self) -> bool:
        if self.idx < len(self.comp_str) or self.cnt < self.size:
            return True
        else:
            return False


# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()
```