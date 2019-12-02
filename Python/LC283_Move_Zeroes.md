# Method 1:
Space optimal. O(1) space.

|Speed|Memory|
|-|-|
|97.98%|100.00%|

```python {.line-numbers}
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        idx, cnt = 0, 0
        while idx<len(nums):
            if nums[idx]!=0:
                nums[cnt] = nums[idx]
                cnt+=1
            idx+=1
        for idx in range(cnt, len(nums)):
            nums[idx]=0
```
