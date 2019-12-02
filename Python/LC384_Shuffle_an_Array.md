# Method 1:
This is another problem of reservoir sampling. The idea is very elegant.

|Speed|Memory|
|-|-|
|87.15%|100.00%|

```python {.line-numbers}
class Solution:

    def __init__(self, nums: List[int]):
        self.size = len(nums)
        self.nums = nums
        self.rand = []

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        self.rand = []
        return self.nums

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        self.rand = [] # For each test case this should be initialized.
        for i in range(self.size):
            self.rand.append(self.nums[i])
            pos = random.randrange(i+1)
            if pos < i:
                self.rand[pos], self.rand[i] = self.rand[i], self.rand[pos]
        return self.rand
            

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
```