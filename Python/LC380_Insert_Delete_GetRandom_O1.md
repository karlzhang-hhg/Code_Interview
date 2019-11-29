# Method 1:
This is pretty straight-forward. I need to remember the index of a value so that I can quickly remove it.

|Speed|Memory|
|---|---|
|98.81%|79.17%|

```python {.line-numbers}
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.map = {} # val -> index
        self.lst = []

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val in self.map:
            return False
        else:
            self.map[val] = len(self.lst)
            self.lst.append(val)
            return True

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val not in self.map:
            return False
        if val != self.lst[-1]:
            idx, last_val = self.map[val], self.lst[-1]
            self.lst[idx] = last_val
            self.map[last_val] = idx
        self.map.pop(val)
        self.lst.pop()
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        # or return random.choice(self.lst)
        return self.lst[random.randrange(0, len(self.lst))]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
```