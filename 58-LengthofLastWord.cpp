class Solution {
public:
    int lengthOfLastWord(string s) {
        int i;
        int curlen = 0;
        int len = 0;
        if(0 == s.length())
        {
            return 0;
        }
        
        for(i = 0; i < s.length(); i++)
        {
            if(s[i] != ' ')
            {
                len++;
            }
            else
            {
                if(len > 0)
                {
                    curlen = len;
                }
                len = 0;
            }
        }
        if(curlen != 0 && len == 0)
        {
            return curlen;
        }
        else
        {
            return len;
            
        }
        
    }
};