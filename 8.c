int myAtoi(char *str) {
    int len;
    len = strlen(str);
    if(len == 0)
    {
        return 0;
    }
    char *pcend = str + len - 1;
    int ret = 0;
    int sum = 0;
    int tmp, sumtmp;
    int flag = 0;
    int max = 2147483647;
    int min = -2147483648;
    
    while((*str == ' ' || *str == '  ' || *str == '\r\n')
          && (str <= pcend))
        
    {
        str++;
    }
    if(str > pcend)
    {
        return ret;
    }
    if(*str == '-')
    {
        flag = 1;
        str++;
    }
    else if(*str == '+')
    {
        str++;
    }
    
    while((*str >= '0' && *str <= '9') && (str <= pcend))
    {
        tmp = (int)(*str - '0');
        sumtmp = sum*10;
        if((flag == 0) && (max/10 >= sum) && ((max - sumtmp) >= tmp))
        {
            sum = tmp + sumtmp;
        }
        else if((flag == 1) && (min/10 <= sum) && ((min + tmp) <= sumtmp))
        {
            sum = sumtmp - tmp;
        }
        else
        {
            if(flag == 1)
            {
                ret = min;
            }
            else
            {
                ret = max;
            }
            return ret;
        }
        str++;
    }
    
    ret = sum;
    return ret;
    
    
    
}