# Method 1:
This is a basic dp problem.

|Speed|Memory|
|-|-|
|89.47%|72.36%|


```python {.line-numbers}
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = nums[0]
        for i in range(1, len(nums)):
            nums[i] = max(nums[i-1]+nums[i], nums[i])
            res = max(res, nums[i])
        return res
```
