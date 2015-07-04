class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ret = true;
        int i;
        int count;
        if(1 == nums.size())
        {
            return ret;
        }
        if(0 == nums[0])
        {
            return false;
        }
        i = nums.size() - 2;
        while(i >=0)
        {
            count = 0;
            if(0 == nums[i])
            {
                i--;
                count++;
                while(i >= 0 && nums[i] <= count)
                {
                    i--;
                    count++;
                    ret = false;
                }
            }
            else
            {
                i--;
                ret = true;
            }
            
        }
        return ret;
    }
};