class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i, j;
        int row = grid.size();
        int col = grid[0].size();
        int array[col];
        array[0] = grid[0][0];
        for(j = 1; j < col; j++)
        {
            array[j] = array[j-1] + grid[0][j];
        }
        for(i = 1; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                if(0 == j || array[j] < array[j-1])
                {
                    array[j] += grid[i][j];
                }
                else
                {
                    array[j] = array[j-1] + grid[i][j];
                }
                
            }
        }
        return array[col-1];
    }
};