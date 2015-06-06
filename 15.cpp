class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums);
};

vector<vector<int>> Solution :: threeSum(vector<int>& nums) {
    int i = 0, j, k;
    vector<vector<int>> retNums;
    
    if(nums.size() < 3)
    {
        return retNums;
    }
    sort(nums.begin(), nums.end());
    k = nums.size() - 1;
    while(i < nums.size() - 2)
    {
        while(i > 0 && i < nums.size() - 2 && nums[i] == nums[i-1])
        {
            i++;
        }
        j = i + 1;
        k = nums.size() - 1;
        while(j < k)
        {
            if(nums[i] + nums[j] + nums[k] < 0)
            {
                j++;
            }
            else if(nums[i] + nums[j] + nums[k] > 0)
            {
                k--;
            }
            else
            {
                vector<int> retOne;
                retOne.push_back(nums[i]);
                retOne.push_back(nums[j]);
                retOne.push_back(nums[k]);
                retNums.push_back(retOne);
                j++;
                k--;
                while(j < nums.size() && nums[j] == nums[j-1] )
                {
                    j++;
                }
                while(0 < k && nums[k] == nums[k+1])
                {
                    k--;
                }
            }
        }
        i++;
    }
    return retNums;
    
}