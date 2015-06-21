class Solution {
private:
    void recursive(int pos, vector<int> one, vector<int>& nums)
    {
        int i, j, tmp;
        if(nums.size() == 0)
        {
            all.push_back(one);
            return;
        }
        for(i = 0; i < nums.size(); i++)
        {
            tmp = nums[i];
            one.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            recursive(i, one, nums);
            nums.insert(nums.begin() + i, tmp);
            one.pop_back();
        }
    }
public:
    vector<vector<int> > all;
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> one;
        if(0 == nums.size())
        {
            return all;
        }
        recursive(0, one, nums);
        return all;
    }
};