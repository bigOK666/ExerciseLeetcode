// 给定一个包含正整数、加(+)、减(-)、乘(*)、除(/)的算数表达式(括号除外)，计算其结果。表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
#include <string>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        vector<int> stack;
        char preSign = '+';
        int num = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + s[i] - '0';
            }

            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)
            {
                switch (preSign)
                {
                case '+':
                    stack.push_back(num);
                    break;
                case '-':
                    stack.push_back(-num);
                    break;
                case '*':
                    stack.back() *= num;
                    break;
                case '/':
                    stack.back() /= num;
                    break;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stack.begin(), stack.end(), 0);
    }
};