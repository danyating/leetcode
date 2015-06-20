class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ret = -1;
        int first = 0;
        int sum = 0;
        int curMax = 0;
        int pos = 0;
        int i,j;
        int n = gas.size();
        vector<int> gap;
        for(i = 0; i < gas.size(); i++)
        {
            gap.push_back(gas[i] - cost[i]);
            sum += gap[i];
        }
        if(0 > sum)
        {
            return -1;
        }
        sum = 0;
        for(i = 0, j = 0; j < gas.size(); i++,j++)
        {
            sum += gap[i];
            if(0 > sum)
            {
                pos = (i + 1)%gas.size();
                j = -1;
                sum = 0;
            }
        }
        return pos;
        
    }
};