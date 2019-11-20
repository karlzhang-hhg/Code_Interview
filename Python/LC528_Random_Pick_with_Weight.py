# Runtime: 204 ms, faster than 97.94% of Python3 online submissions for Random Pick with Weight.
# Memory Usage: 17.1 MB, less than 60.00% of Python3 online submissions for Random Pick with Weight.
# O(nlogb), n: number of random draws, b: number of bins

class Solution:

    def __init__(self, w: List[int]):
        self.pmf = w
        for i in range(len(self.pmf)):
            if i>0:
                self.pmf[i]+=self.pmf[i-1]
        # self.pmf = [w[i]+w[i-1] if i>0 else w[i] for i in range(len(w))] # This is wrong

    def pickIndex(self) -> int:
        return bisect.bisect_left(self.pmf, random.uniform(0, 1)*self.pmf[-1])


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()

# V2
# Runtime: 256 ms, faster than 90.09% of Python3 online submissions for Random Pick with Weight.
# Memory Usage: 17.3 MB, less than 46.67% of Python3 online submissions for Random Pick with Weight.

class Solution:

    def __init__(self, w: List[int]):
        self.pmf = w
        self.n = len(self.pmf)
        for i in range(self.n):
            if i>0:
                self.pmf[i]+=self.pmf[i-1]
        # self.pmf = [w[i]+w[i-1] if i>0 else w[i] for i in range(len(w))] # This is wrong

    def pickIndex(self) -> int:
        rnum = random.uniform(0, 1)*self.pmf[-1]
        l, r = 0, self.n-1
        while l<r:
            m=l+(r-l)//2
            if self.pmf[m]>=rnum:
                r=m
            else:
                l=m+1
        return l

# If I import numpy and use np.random, the time would be very long