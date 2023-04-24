#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int maxans = 0;
        stack<int> index;
        index.push(-1);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                index.push(i);
            }
            else
            {
                index.pop();
                if (index.empty())
                {
                    index.push(i);
                }
                else
                {
                    maxans = max(maxans, i - index.top());
                }
            }
        }
        return maxans;
    }
};