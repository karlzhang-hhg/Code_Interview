# Runtime: 892 ms, faster than 6.03% of Python3 online submissions for Longest Arithmetic Subsequence of Given Difference.
# Memory Usage: 25.5 MB, less than 100.00% of Python3 online submissions for Longest Arithmetic Subsequence of Given Difference.
# Clear version, O(nlog(n)) complexity

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        m_idx = {}
        for i, v in enumerate(arr):
            if v in m_idx:
                m_idx[v].append(i)
            else:
                m_idx[v]=[i]
        
        res = 1
        if difference==0:
            for v, idx in m_idx.items():
                res = max(res, len(idx))
            return res
        
        for v, idx in m_idx.items():
            pre_v = v-difference
            pre_idx = m_idx[pre_v] if pre_v in m_idx else []
            for i in idx:
                pre_v_i = bisect.bisect(pre_idx, i)
                arr[i] = pre_idx[pre_v_i-1] if pre_v_i > 0 else -1
        
        for i, pre_i in enumerate(arr):
            arr[i] = (1+arr[pre_i]) if pre_i >=0 else 1
            res = max(res, arr[i])
            
        return res


# Runtime: 996 ms, faster than 5.06% of Python3 online submissions for Longest Arithmetic Subsequence of Given Difference.
# Memory Usage: 25.5 MB, less than 100.00% of Python3 online submissions for Longest Arithmetic Subsequence of Given Difference.
# O(n) complexity. Hard to write.

class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        m_idx = {}
        for i, v in enumerate(arr):
            if v in m_idx:
                m_idx[v].append(i)
            else:
                m_idx[v]=[i]
        
        res = 1
        if difference==0:
            for v, idx in m_idx.items():
                res = max(res, len(idx))
            return res
        
        for v, idx in m_idx.items():
            pre_v = v-difference
            pre_i, i = 0, 0
            pre_idx = m_idx[pre_v] if pre_v in m_idx else []
            pre_v_idx = -1
            while i < len(idx):
                while i<len(idx) and (pre_i >= len(pre_idx) or pre_idx[pre_i] > idx[i]):
                    arr[idx[i]] = pre_v_idx
                    i+=1
                while i<len(idx) and pre_i < len(pre_idx) and pre_idx[pre_i] < idx[i]:
                    pre_i+=1
                pre_v_idx = pre_idx[pre_i-1] if pre_i >= 1 else -1
        
        for i, pre_i in enumerate(arr):
            arr[i] = (1+arr[pre_i]) if pre_i >=0 else 1
            res = max(res, arr[i])
            
        return res