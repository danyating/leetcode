#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) ;
};

vector<int> Solution :: twoSum(vector<int>& nums, int target) {
    int i, j, k;
    vector<int> copyNums;
    vector<int> retIndex;
    for(i = 0; i < nums.size(); i++)
    {
        copyNums.push_back(nums[i]);
    }
    sort(copyNums.begin(), copyNums.end());
    j = copyNums.size() - 1;
    i = 0;
    while(i != j && copyNums[i] + copyNums[j] != target)
    {
        if(copyNums[i] + copyNums[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    for(k = 0; k < nums.size(); k++)
    {
        if(copyNums[i] == nums[k] || copyNums[j] == nums[k])
        {
            retIndex.push_back(k + 1);
        }
    }
    return retIndex;
}