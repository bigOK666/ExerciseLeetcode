#include <stack>
using namespace std;

class Browser
{
public:
    Browser() {}

    void newPage(int page)
    {
        pagesAtBack.push(page);
        pagesAtFront = stack<int>();
    }

    int back()
    {
        pagesAtFront.push(pagesAtBack.top());
        pagesAtBack.pop();
        return pagesAtBack.top();
    }

    int forward()
    {
        pagesAtBack.push(pagesAtFront.top());
        pagesAtFront.pop();
        return pagesAtBack.top();
    }

private:
    stack<int> pagesAtBack;
    stack<int> pagesAtFront;
};