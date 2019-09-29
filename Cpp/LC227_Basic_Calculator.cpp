#include <string>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int res = 0, num = 0, cur_res = 0, n = s.size();
        char op = '+';
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if (c >= '0' && c <= '9')
            {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1)
            {
                switch (op)
                {
                case '+':
                    cur_res += num;
                    break;
                case '-':
                    cur_res -= num;
                    break;
                case '*':
                    cur_res *= num;
                    break;
                case '/':
                    cur_res /= num;
                    break;
                }
            }
            if (c == '+' || c == '-' || i == n - 1)
            {
                res += cur_res;
                cur_res = 0;
            }
            num = 0;
            op = c;
        }
        return res;
    }
}