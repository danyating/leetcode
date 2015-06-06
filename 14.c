char *longestCommonPrefix(char *strs[], int n) {
    char *s = (char*)malloc(0xffff);
    memset(s, 0, 0xffff);
    int k = 0;
    int max = 0xffff;
    int i;
    int len1, len2;
    if(n == 0)
    {
        return s;
    }
    for(i = 0; i < n-1; i++)
    {   k = 0;
        len1 = strlen(strs[i]);
        len2 = strlen(strs[i+1]);
        while((*(strs[i]+k) == *(strs[i+1]+k)) && (k < max)
              && (k < len1) && (k < len2))
        {
            k++;
            
        }
        if(k < max)
        {
            max = k;
        }
        
    }
    
    memcpy(s, strs[0], max);
    
}