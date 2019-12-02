# Method 1:
This method is truely time-O(1) method.

|Speed|Memory|
|-|-|
|98.19%|100.00%|


```python {.line-numbers}
class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.size = size
        self.wind = []
        self.sum = 0
        self.cur_idx = 0

    def next(self, val: int) -> float:
        if len(self.wind)<self.size:
            self.sum += val
            self.cur_idx += 1
            self.wind.append(val)
            res = self.sum/len(self.wind)
        else:
            self.cur_idx = self.cur_idx%self.size
            self.sum -= self.wind[self.cur_idx]
            self.wind[self.cur_idx] = val
            self.sum += val
            self.cur_idx += 1
            res = self.sum/self.size
        return res


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```