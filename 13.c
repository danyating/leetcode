int romanToInt(char *s) {
    int len;
    int ret;
    int minus = 0;
    len = strlen(s);
    char *pcend = s + len -1;
    char *tmp = s;
    char *pre = s;
    int alp[255] = {0};
    
    
    while(tmp <= pcend)
    {
        alp[*tmp]++;
        
        if((*tmp == 'V' || *tmp == 'X') && *pre == 'I')
        {
            minus += 1;
        }
        
        if((*tmp == 'L' || *tmp == 'C')&& *pre == 'X')
        {
            minus += 10;
        }
        
        if((*tmp == 'D' || *tmp == 'M') && *pre == 'C')
        {
            minus += 100;
        }
        
        pre = tmp;
        tmp++;
    }
    
    ret = 1*alp['I'] + 5*alp['V'] + 10*alp['X'] +50*alp['L'] + 100*alp['C'] + 500*alp['D'] +1000*alp['M'];
    ret = ret - minus*2;
    
    return ret;
    
}




