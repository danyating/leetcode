class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target);
};

int Solution :: threeSumClosest(vector<int>& nums, int target)
{
    int i = 0, j, k;
    int ret;
    int retMin;
    int min = 0xffffff;
    int error;
    sort(nums.begin(), nums.end());
    while(i < nums.size())
    {
        j = i+1;
        k = nums.size() - 1;
        while(j < k)
        {
            ret = nums[i] + nums[j] + nums[k];
            if(ret < target)
            {
                j++;
                error = target - ret;
            }
            else
            {
                k--;
                error = ret - target;
            }
            if(error < min)
            {
                min = error;
                retMin = ret;
            }
            
        }
        i++;
    }
    return retMin;
    
}