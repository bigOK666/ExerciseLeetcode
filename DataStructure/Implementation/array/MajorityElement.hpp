/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
还可以先排序，然后中间那个数就是，因为题中给了一定有个数出现超过n/2
还可以用投票法

*/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> paires;
        int counts = 0;
        int majority = 0;
        for (auto num : nums)
        {
            ++paires[num];
            if (paires[num] > counts)
            {
                counts = paires[num];
                majority = num;
            }
        }
        return majority;
    }
};