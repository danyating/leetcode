class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        int flag = 0;
        int num;
        string ret;
        while(i >= 0 || j >= 0)
        {
            if(i >= 0 && j >= 0)
            {
                num = a[i] -'0' + b[j] -'0' + flag;
            }
            else if(i >= 0)
            {
                num = a[i] -'0' + flag;
            }
            else
            {
                num = b[j] -'0' + flag;
            }
            if(num >= 2)
            {
                num = num - 2;
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            ret.insert(ret.begin(), char(num + '0'));
            i--;
            j--;
        }
        if(1 == flag)
        {
            ret.insert(ret.begin(), '1');
        }
        return ret;
    }
};