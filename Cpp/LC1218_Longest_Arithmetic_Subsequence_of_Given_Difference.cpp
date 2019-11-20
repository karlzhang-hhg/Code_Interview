// Runtime: 152 ms, faster than 91.54% of C++ online submissions for Longest Arithmetic Subsequence of Given Difference.
// Memory Usage: 23.4 MB, less than 100.00% of C++ online submissions for Longest Arithmetic Subsequence of Given Difference.
// Very clean version, fast implementation


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        unordered_map<int, int> dp;
        int res = 1;
        for (auto a : arr)
            res = max(res, dp[a]=dp[a-d]+1);
        
        return res;
    }
};
