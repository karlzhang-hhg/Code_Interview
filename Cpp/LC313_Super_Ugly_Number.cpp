// Write a program to find the nth super ugly number.

// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.

// Example:

// Input: n = 12, primes = [2,7,13,19]
// Output: 32
// Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12
//              super ugly numbers given primes = [2,7,13,19] of size 4.
// Note:

// 1 is a super ugly number for any given primes.
// The given numbers in primes are in ascending order.
// 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
// The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

#include <vector>
#include <climits>
#include <map>
#include <string>
#include <boost/functional/hash.hpp>
using namespace std;

typedef pair<int, int> keyT;

class Solution
{
public:
    // // For map version
    // // Or:
    // struct comp
    // {
    //     template <typename T>
    //     bool operator()(const T &l, const T &r) const
    //     {
    //         if (l.first == r.first)
    //             return l.second > r.second;

    //         return l.first < r.first;
    //     }
    // };

    // // Cannot use lambda function.
    // struct comp
    // {
    //     bool operator()(const keyT &l, const keyT &r) const
    //     {
    //         if (l.first == r.first)
    //             return l.second > r.second;

    //         return l.first < r.first;
    //     }
    // };

    // priority_queue version.
    struct comp
    {
        bool operator()(const vector<int> &r, const vector<int> &l) const
        {
            if (l[0] == r[0])
                return l[0] > r[0];

            return l[0] < r[0];
        }
    };

    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        // =============================================================================
        // // Runtime: 40 ms, faster than 87.08% of C++ online submissions for Super Ugly Number.
        // // Memory Usage: 9.8 MB, less than 88.89% of C++ online submissions for Super Ugly Number.

        // vector<int> res;
        // res.push_back(1);
        // int n_p = primes.size();
        // vector<int> idx(n_p, 0);
        // while (res.size() < n)
        // {
        //     int mn = INT_MAX, tmp[n_p];
        //     for (int i = 0; i < n_p; ++i)
        //     {
        //         tmp[i] = res[idx[i]] * primes[i];
        //         mn = min(mn, tmp[i]);
        //     }
        //     for (int i = 0; i < n_p; ++i)
        //     {
        //         if (tmp[i] == mn)
        //         {
        //             idx[i]++;
        //         }
        //     }
        //     res.push_back(mn);
        // }
        // return res.back();

        // =============================================================================
        // Runtime: 136 ms, faster than 24.27% of C++ online submissions for Super Ugly Number.
        // Memory Usage: 44 MB, less than 22.22% of C++ online submissions for Super Ugly Number.

        // vector<int> res;
        // res.push_back(1);
        // int n_p = primes.size();
        // map<keyT, int, comp> heap;
        // for (int i = 0; i < n_p; ++i)
        // {
        //     heap.emplace(keyT(primes[i], i), 0);
        // }

        // while (res.size() < n)
        // {
        //     pair<keyT, int> head = *(heap.begin());
        //     int cur_val = head.first.first, p_idx = head.first.second, res_idx = head.second;
        //     if (cur_val != res.back())
        //     {
        //         res.push_back(cur_val);
        //     }
        //     heap.erase(heap.begin());
        //     int next_val = res[res_idx + 1] * primes[p_idx];
        //     heap.emplace(keyT(next_val, p_idx), res_idx + 1);
        // }
        // return res.back();

        // =============================================================================
        // Runtime: 380 ms, faster than 11.57% of C++ online submissions for Super Ugly Number.
        // Memory Usage: 48 MB, less than 22.22% of C++ online submissions for Super Ugly Number.

        vector<int> res{1};
        int n_p = primes.size();
        priority_queue<vector<int>, vector<vector<int>>, comp> heap;
        for (int i = 0; i < n_p; ++i)
        {
            heap.emplace(vector<int>{primes[i], 0, i});
        }
        while (res.size() < n)
        {
            vector<int> head = heap.top();
            heap.pop();
            if (res.back() != head[0])
            {
                res.push_back(head[0]);
            }
            int res_idx = head[1], p_idx = head[2];
            int next_val = res[res_idx + 1] * primes[p_idx];
            heap.emplace(vector<int>{next_val, res_idx + 1, p_idx});
        }
        return res.back();
    }
};