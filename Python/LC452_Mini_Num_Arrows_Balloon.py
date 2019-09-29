class Solution:

    # # Runtime: 696 ms, faster than 5.25% of Python3 online submissions for Minimum Number of Arrows to Burst Balloons.
    # # Memory Usage: 22.9 MB, less than 16.67% of Python3 online submissions for Minimum Number of Arrows to Burst Balloons.

    # def findMinArrowShots(self, points: List[List[int]]) -> int:
    #     points.sort(key=lambda x: x[0])
    #     bds = {}
    #     for idx, bal in enumerate(points):
    #         if bal[0] in bds:
    #             bds[bal[0]][0].append(idx)
    #         else:
    #             bds[bal[0]] = [[idx], []]
    #         if bal[1] in bds:
    #             bds[bal[1]][1].append(idx)
    #         else:
    #             bds[bal[1]] = [[], [idx]]

    #     bds_sorted = []
    #     for k, v in bds.items():
    #         bds_sorted.append([k, v])
    #     bds_sorted.sort(key=lambda x: x[0])

    #     cnt = 0
    #     cur_bals = []
    #     last_bal_idx = -1
    #     for bd in bds_sorted:
    #         cur_bals.extend(bd[1][0])
    #         if max(bd[1][1]) > last_bal_idx:
    #             cnt += 1
    #             last_bal_idx = max(cur_bals)
    #             cur_bals = []

    #     return cnt

    # # Runtime: 556 ms, faster than 5.25% of Python3 online submissions for Minimum Number of Arrows to Burst Balloons.
    # # Memory Usage: 19.1 MB, less than 16.67% of Python3 online submissions for Minimum Number of Arrows to Burst Balloons.
    # def findMinArrowShots(self, points: List[List[int]]) -> int:
    #     points.sort()
    #     starts = [pt[0] for pt in points]
    #     ends = [[pt[1], idx] for idx, pt in enumerate(points)]
    #     ends.sort()
    #     set_ends = set([])
    #     ei = 0
    #     cnt = 0
    #     last_si = -1
    #     while ei < len(ends):
    #         si = ends[ei][1]
    #         pt = points[si]
    #         if pt[1] not in set_ends and si > last_si:
    #             last_si = bisect.bisect_right(starts, pt[1])-1
    #             set_ends.add(pt[1])
    #             cnt += 1
    #         ei += 1

    #     return cnt

    # Runtime: 500 ms, faster than 33.45% of Python3 online submissions for Minimum Number of Arrows to Burst Balloons.
    # Memory Usage: 19 MB, less than 16.67% of Python3 online submissions for Minimum Number of Arrows to Burst Balloons.

    def findMinArrowShots(self, points: List[List[int]]) -> int:
        cnt = 0
        if len(points) == 0:
            return cnt
        points.sort()

        end = points[0][1]
        cnt += 1
        for pt in points[1:]:
            if pt[0] <= end:
                end = min(end, pt[1])
            else:
                cnt += 1
                end = pt[1]
        return cnt
