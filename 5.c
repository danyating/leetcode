char *longestPalindrome(char *s) {
    char *palin = (char*)malloc(sizeof(char)*2000);
    memset(palin, 0, 1000);
    char *i, *j, *m, *p;
    char *pos,*position;
    int palinlenodd = 1;
    int max = 0;
    int maxpalinlen = 0;
    int palinleneven = 0;
    int len = (int)strlen(s);
    pos = s;
    
    for(i = s; i < s + len; i++)
    {
        palinlenodd = 1;
        palinleneven = 0;
        for(j = i-1; j >= s; j--)
        {
            p = i - j + i;
            if(p >= s + len)
            {
                break;
            }
            if(*j == *p)
            {
                palinlenodd += 2;
            }
            else
            {
                break;
            }
        }
        
        for(m = i-1; m >= s; m--)
        {
            p = i - m - 1 + i;
            if(p >= s + len)
            {
                break;
            }
            if(*m == *p)
            {
                palinleneven += 2;
            }
            else
            {
                break;
            }
            
        }
        if(palinlenodd < palinleneven)
        {
            max = palinleneven;
            position = m;
        }
        else
        {
            max = palinlenodd;
            position = j;
        }
        if(max > maxpalinlen)
        {
            maxpalinlen = max;
            pos = ++position;
        }
        
    }
    memcpy(palin, pos, maxpalinlen);
    return palin;
    
    
    
}