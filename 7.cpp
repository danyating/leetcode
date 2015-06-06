class Solution {
public:
    int reverse(int x) {
        int tmp[16] = {0};
        int flag = 0;
        int max = 0x7fffffff;
        int i,j;
        int y = 0;
        if(x == 0)
        {
            return x;
        }
        if(x < 0)
        {
            flag = 1;
        }
        for(i = 0; x != 0; i++)
        {
            tmp[i] = x%10;
            x = x/10;
        }
        i--;
        for(j = i; j>=0; j--)
        {
            if((max - abs(y)) < abs(tmp[j]*pow(10,(i-j))))
                return 0;
            y += tmp[j]*pow(10,(i-j));
        }
        
        return y;
    }
};