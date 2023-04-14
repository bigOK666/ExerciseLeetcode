/*Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.*/

#include <vector>

using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int length = nums.size();

        for (int i = 0; i < length; i++)
        {
            // 当两个要交换的值相等时也不交换
            while (nums[i] > 0 && nums[i] <= length && nums[i] != (i + 1) && nums[i] != nums[nums[i] - 1])
            {
                swap(nums, i, nums[i] - 1);
            }
        }

        for (int i = 0; i < length; i++)
        {
            if (nums[i] != (i + 1))
            {
                return (i + 1);
            }
        }

        return (length + 1);
    }

private:
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
