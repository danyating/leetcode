#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s);
};

int Solution :: lengthOfLongestSubstring(string s)
{
    int len = s.size();
    int i = 0, j, k = -1;
    int count = 0;
    int max = 0;
    int position[256] = {0xffff};
    int isRepeat[256] = {0};
    while(i < len)
    {
        if(isRepeat[s[i]] == 0)
        {
            position[s[i]] = i;
            isRepeat[s[i]] = 1;
            count++;
        }
        else
        {
            if(max < count)
            {
                max = count;
            }
            count = count + k - position[s[i]] + 1;
            for(j = k+1; j < position[s[i]]; j++)
            {
                isRepeat[s[j]] = 0;
            }
            k = position[s[i]];
            position[s[i]] = i;
            
        }
        i++;
    }
    if(max < count)
    {
        max = count;
    }
    return max;
    
}