char *convert(char *s, int nRows) {
    char *c = (char*)malloc(sizeof(char)*2000);
    memset(c, 0, 2000);
    int len = strlen(s);
    int i,j = 0;
    int tmp ;
    int tmp1 ;
    char *pos = s;
    
    if(nRows == 1)
    {
        memcpy(c, s, len);
        return c;
    }
    
    for(i = 1; i <= nRows; i++)
    {
        tmp = 2*(nRows - i);
        tmp1 = 2*(i - 1);
        pos = s + i - 1;
        for(j; pos < s + len;)
        {
            if(pos < s + len)
            {
                c[j++] = *pos;
                pos = pos + tmp;
            }
            if(pos < s + len)
            {
                if((tmp != 0) && (tmp1 != 0))
                {
                    c[j++] = *pos;
                }
                pos = pos + tmp1;
            }
        }
    }
    return c;
    
    
}