class Solution:
    # Runtime: 176 ms, faster than 91.23% of Python3 online submissions for Russian Doll Envelopes.
    # Memory Usage: 16 MB, less than 20.00% of Python3 online submissions for Russian Doll Envelopes.
    def maxEnvelopes(self, env: List[List[int]]) -> int:
        # Without this, there could be a case that same width with different height can be added in sequence.
        env.sort(key=lambda x: (x[0], -x[1]))
        n = len(env)
        if n == 0:
            return 0
        mis = []
        for i in range(n):
            idx = bisect.bisect_left(mis, env[i][1])
            if idx == len(mis):
                mis.append(env[i][1])
            else:
                mis[idx] = env[i][1]
        return len(mis)

    # # Or similar to alg above.
    # def maxEnvelopes(self, env: List[List[int]]) -> int:
    #     env.sort(key=lambda x: (x[0], -x[1]))
    #     n = len(env)
    #     if n==0:
    #         return 0
    #     mis = [env[0][1]]
    #     for i in range(1, n):
    #         if env[i][1]>mis[-1]:
    #             mis.append(env[i][1])
    #         idx = bisect.bisect_left(mis, env[i][1])
    #         mis[idx] = env[i][1]
    #     return len(mis)

# # TLE
#    def maxEnvelopes(self, env: List[List[int]]) -> int:
#         env.sort()
#         n = len(env)
#         if n==0:
#             return 0
#         res = 1
#         mis = [1]*n
#         for i in range(1, n):
#             for j in range(i):
#                 if env[j][0] == env[i][0]:
#                     break
#                 elif env[j][1] < env[i][1]:
#                     mis[i] = max(mis[i], mis[j]+1)
#             res = max(res, mis[i])

#         return res
