char *intToRoman(int num) {
    int ge;
    int shi;
    int bai;
    int qian;
    char *s = (char*)malloc(sizeof(char)*125);
    memset(s,0,125);
    
    char cge[][5] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char cshi[][5] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char cbai[][5] =  {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char cqian[][5] = {"M", "MM", "MMM"};
    ge = num %10;
    shi = num/10%10;
    bai = num/100%10;
    qian = num/1000%10;
    
    if(qian != 0)
    {
        strcat(s, cqian[qian-1]);
    }
    if(bai != 0)
    {
        strcat(s, cbai[bai-1]);
    }
    if(shi != 0)
    {
        strcat(s, cshi[shi-1]);
    }
    if(ge != 0)
    {
        strcat(s, cge[ge-1]);
    }
    
    return s;
    
}

