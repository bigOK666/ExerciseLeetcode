#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> lefts;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                lefts.push(c);
            }
            else
            {
                if (lefts.empty())
                {
                    return false;
                }

                if (c == ')')
                {
                    if (lefts.top() != '(')
                    {
                        return false;
                    }
                    lefts.pop();
                }

                if (c == '}')
                {
                    if (lefts.top() != '{')
                    {
                        return false;
                    }
                    lefts.pop();
                }

                if (c == ']')
                {
                    if (lefts.top() != '[')
                    {
                        return false;
                    }
                    lefts.pop();
                }
            }
        }

        return lefts.empty();
    }
};