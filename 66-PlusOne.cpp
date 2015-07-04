class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        int flag = 1;
        vector<int> ret;
        vector<int> reverse;
        for(i = digits.size() - 1; i >= 0; i--)
        {
            
            digits[i] = digits[i] + flag;
            if(9 < digits[i])
            {
                digits[i] -= 10;
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            ret.insert(ret.begin(), digits[i]);
        }
        if(1 == flag)
        {
            ret.insert(ret.begin(), 1);
        }
        
        return ret;
    }
};