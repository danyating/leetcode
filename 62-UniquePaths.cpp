class Solution {
public:
    int uniquePaths(int m, int n) {
        int i=1, j=1;
        int min = (m > n) ? n : m;
        int max = (m > n) ? m : n;
        int array[min];
        for(j = 0; j < min; j++)
        {
            array[j] = 1;
        }
        for(i = 1; i < max; i++)
        {
            for(j = 1; j < min; j++)
            {
                array[j] += array[j -1];
            }
        }
        return array[min-1];
    }
};
