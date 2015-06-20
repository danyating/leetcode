class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix);
};

vector<int> Solution :: spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> ret;
    int m = matrix.size();
    if (0 == m)
        return ret;
    int n = matrix[0].size();
    int lUp[2] = {0, 0};
    int rDown[2] = {m-1, n-1}; //右下角坐标
    int i=0, j=0;
    
    while(lUp[0] <= rDown[0] && lUp[1] <= rDown[1])
    {
        j = lUp[1];
        while(j <= rDown[1])
        {
            ret.push_back(matrix[lUp[0]][j]);
            j++;
        }
        i = lUp[0] + 1;
        while(i <= rDown[0])
        {
            ret.push_back(matrix[i][rDown[1]]);
            i++;
        }
        
        j = rDown[1] - 1;
        if(lUp[0] != rDown[0])
        {
            while(j >= lUp[1])
            {
                ret.push_back(matrix[rDown[0]][j]);
                j--;
            }
        }
        
        i = rDown[0] - 1;
        if(lUp[1] != rDown[1])
        {
            while(i > lUp[0])
            {
                ret.push_back(matrix[i][lUp[1]]);
                i--;
            }
        }
        
        lUp[0]++;
        lUp[1]++;
        rDown[0]--;
        rDown[1]--;
        
    }
    return ret;
}

