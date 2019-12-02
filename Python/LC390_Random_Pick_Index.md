# Method 1:
The statement of this problem is not easy to understand. It wants me to design an algorithm, so that the size of numbers is large and we want to randomly sample an index with value equals the target. This needs [reservior sampling]() method. 

|Speed|Memory|
|-|-|
|91.75%|33.33%|

```python {.line-numbers}
class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        cnt = 0
        for i, num in enumerate(self.nums):
            if num!=target: continue
            else:
                cnt += 1
                if (random.randrange(cnt)==0): res = i
        return res
                


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
```