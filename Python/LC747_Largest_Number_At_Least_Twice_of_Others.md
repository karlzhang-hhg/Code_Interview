# Method 1:
Iterate the list myself. Be careful how I update the `l1` and `l2`. And how to use `float('inf')`. Note that when check a number is infinity or not, use `num==float('inf')`. Don't use `num is float('inf')`.


|Speed|Memory|
|---|---|
|99.29%|100.00%|

```python {.line-numbers}

class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        l1, l2, idx = -float('inf'), -float('inf'), -1
        for i, num in enumerate(nums):
            if num>l1:
                l2, l1, idx = l1, num, i
            elif num>l2:
                l2 = num
        if l2==-float('inf') or l2==0 or l1//l2>=2: return idx
        else: return -1
```


# Method 2:
Leetcode answer. Very concise.

|Speed|Memory|
|---|---|
|99.26%|100.00%|

```python {.line-numbers}
class Solution(object):
    def dominantIndex(self, nums):
        m = max(nums)
        if all(m >= 2*x for x in nums if x != m):
            return nums.index(m)
        return -1
```