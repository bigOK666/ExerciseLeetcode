/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/
#include <vector>
#include<set>
using namespace std;
class Solution{
    public:
    vector<vector<int>> threeSum(vector<int> &nums){
        int n=nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> findings;
        vector<vector<int>> output;
        for(int i=0;i<n-2;i++){
            int low=i+1, high=n-1;
            while(low<high){
                if(nums[i]+nums[low]+nums[high]<0){
                    low++;
                }else if(nums[i]+nums[low]+nums[high]){
                    high--;
                }else{
                    findings.insert({nums[i], nums[low],nums[high]});
                    low++;
                    high--;
                }
            }
        }

        for(auto value:findings){
            output.push_back(value);
        }
        return output;
    }
};