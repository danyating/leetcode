class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pre, end, i;
        int tmp;
        if(0 == nums.size())
        {
            return;
        }
        pre = 0;
        end = nums.size() - 1;
        for(i = 0; i <= end; i++)
        {
            if(0 == nums[i])
            {
                if(pre != i)
                {
                    //不等的情况下i不能往前移，故i先减个1
                    nums[i] = nums[pre];
                    nums[pre] = 0;
                    i--;
                }
                pre++;
            }
            else if(2 == nums[i])
            {
                if(end != i)
                {
                    nums[i] = nums[end];
                    nums[end] = 2;
                    i--;
                }
                end--;
            }
        }
        
    }
};