# Method 1:
The following three methods have similar time and space. The Leetcode solution has similar complexity. 

|Speed|Memory|
|-|-|
|92.30%|6.52%|

```python {.line-numbers}
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals)==0: return []
        intervals.sort(key=lambda x: x[0])
        res, idx = [intervals[0]], 1
        while idx < len(intervals):
            if res[-1][1]>=intervals[idx][0]:
                res[-1][1]=max(res[-1][1], intervals[idx][1])
            else:
                res.append(intervals[idx])
            idx+=1
        return res
```

```python {.line-numbers}
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals)==0: return []
        intervals.sort(key=lambda x: x[0])
        res = [intervals[0]]
        while len(intervals)>0:
            if res[-1][1]>=intervals[0][0]:
                res[-1][1]=max(res[-1][1], intervals[0][1])
            else:
                res.append(intervals[0])
            intervals.pop(0)
        return res
```

```python {.line-numbers}
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals)==0: return []
        intervals.sort(key=lambda x: x[0])
        idx = 1
        while idx<len(intervals):
            if intervals[idx-1][1]>=intervals[idx][0]:
                intervals[idx-1][1] = max(intervals[idx-1][1], intervals[idx][1])
                intervals.pop(idx)
            else:
                idx += 1
        return intervals
```