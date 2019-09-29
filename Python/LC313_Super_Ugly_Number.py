# Write a program to find the nth super ugly number.

# Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

# Example:

# Input: n = 12, primes = [2,7,13,19]
# Output: 32
# Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12
#              super ugly numbers given primes = [2,7,13,19] of size 4.
# Note:

# 1 is a super ugly number for any given primes.
# The given numbers in primes are in ascending order.
# 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
# The nth super ugly number is guaranteed to fit in a 32-bit signed integer.


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        # Runtime: 292 ms, faster than 97.69% of Python3 online submissions for Super Ugly Number.
        # Memory Usage: 20.3 MB, less than 100.00% of Python3 online submissions for Super Ugly Number.
        #

        # def nthSuperUglyNumberHelper(n, primes):
        #     if n == 1:
        #         return 1
        #     ls_heads = [(p, 0, p_idx) for p_idx, p in enumerate(primes)]
        #     heapq.heapify(ls_heads)
        #     res = [1]
        #     while len(res) < n:
        #         next_val, res_idx, p_idx = ls_heads[0]
        #         if next_val != res[-1]:
        #             res.append(next_val)
        #         heapq.heapreplace(
        #             ls_heads, (res[res_idx+1]*primes[p_idx], res_idx+1, p_idx))
        #     return res[-1]

        # Runtime: 1196 ms, faster than 15.03% of Python3 online submissions for Super Ugly Number.
        # Memory Usage: 17.3 MB, less than 100.00% of Python3 online submissions for Super Ugly Number.
        def nthSuperUglyNumberHelper(n, primes):
            if n == 1:
                return 1
            res = [1]
            k = len(primes)
            ls_idx = [0 for _ in range(k)]
            tmp = [0 for _ in range(k)]
            while len(res) < n:
                mn = float("inf")
                for i in range(k):
                    tmp[i] = res[ls_idx[i]]*primes[i]
                for i in range(k):
                    mn = min(mn, tmp[i])
                for i in range(k):
                    if mn == tmp[i]:
                        ls_idx[i] += 1
                res.append(mn)
            return res[-1]

        return nthSuperUglyNumberHelper(n, primes)
