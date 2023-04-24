#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> expressions;
        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {
            string &token = tokens[i];
            if (isNum(token))
            {
                expressions.push(atoi(token.c_str()));
            }
            else
            {
                int right = expressions.top();
                expressions.pop();
                int left = expressions.top();
                expressions.pop();
                switch (token[0])
                {
                case '+':
                    expressions.push(left + right);
                    break;
                case '-':
                    expressions.push(left - right);
                    break;
                case '*':
                    expressions.push(left * right);
                    break;
                case '/':
                    expressions.push(left / right);
                    break;
                }
            }
        }
        return expressions.top();
    }

    bool isNum(const string &token)
    {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};