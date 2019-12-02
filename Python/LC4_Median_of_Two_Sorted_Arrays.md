# Method 1:
For this problem, I first find out which array is larger. I also treat the case that one array is empty as special case, because it doesn't fit the latter binary search ending condition. I confined the index range in the longer array, because we know that the number of elements no-larger or no-smaller than a specific element shouldn't be larger than a certain value (`end_num`). This way, we can make sure the `idx` we calculate for the shorter array is within index range, except the last one `m`. In the last, after we find potential index, we have to consider all values near that index, because we don't know which of those sit exactly at the positions of median. In this way, we confined our candidates to at most four elements. We just need to find the smallest two or one of them.


|Speed|Memory|
|---|---|
|99.31%|100.00%|

```python {.line-numbers}
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) < len(nums2):
            nums1, nums2 = nums2, nums1
        n, m = len(nums1), len(nums2)
        if m==0:
            return (nums1[(n-1)//2]+nums1[n//2])/2
        
        end_num = (n+m-1)//2
        
        l, r = n-end_num-1, end_num
        while l<r:
            mid = (l+r)//2
            idx = end_num-mid
            if idx>0 and nums1[mid]<nums2[idx-1]: l = mid+1
            else: r = mid
        ls_cand = []
        ls_cand.append(nums1[l])
        if l+1<n: ls_cand.append(nums1[l+1])
        idx = end_num-l
        # This condition is necessary.
        if idx < m: 
            # It could be the case that idx==0 and nums1[l-1]>=nums2[idx]
            if l-1>=0 and nums1[l-1]>=nums2[idx]: ls_cand.append(nums1[l-1])
            else: ls_cand.append(nums2[idx])
            if idx+1<m: ls_cand.append(nums2[idx+1])
        ls_cand.sort()
        if (n+m)%2: return ls_cand[0]
        else: return (ls_cand[0]+ls_cand[1])/2
```