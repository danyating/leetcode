class Solution {
public:
    vector<vector<string> > solveQueen;
    vector<vector<string> > solveNQueens(int n);
private:
    bool isValid(int queen[], int row, int col);
    void recursive(int queen[], int row, int n);
    void fillSolution(int queen[], int n);
    
};

void Solution :: fillSolution(int queen[], int n)
{
    int i,j;
    vector<string> oneGroup;
    for(i = 0; i < n; i++)
    {
        string s;
        for(j = 0; j < n; j++)
        {
            if(j == queen[i])
            {
                s.append(1, 'Q');
            }
            else
            {
                s.append(1, '.');
            }
        }
        oneGroup.push_back(s);
    }
    solveQueen.push_back(oneGroup);
}

bool Solution :: isValid(int queen[], int row, int col)
{
    int i;
    bool ret = true;
    for(i = 0; i < row; i++)
    {
        if(queen[i] == col || row - i == queen[i] - col ||
           row - i == col - queen[i])
        {
            ret = false;
            break;
        }
    }
    return ret;
}

void Solution :: recursive(int queen[], int row, int n)
{
    int col;
    if(row == n)
    {
        fillSolution(queen, n);
        return;
    }
    for(col = 0; col < n; col++)
    {
        if(isValid(queen, row, col))
        {
            queen[row] = col;
            recursive(queen, row+1, n);
            queen[row] = 0xffff;
        }
    }
    
}

vector<vector<string> > Solution :: solveNQueens(int n)
{
    int queen[n] = {0xffff};
    int row = 0, col = 0;
    while(row >= 0)
    {
        while(col < n && !isValid(queen, row, col))
        {
            col++;
        }
        if(n == col)
        {
            row--;
            col = queen[row] + 1;
        }
        else
        {
            queen[row] = col;
            if(row == n-1)
            {
                fillSolution(queen, n);
                col++;
                queen[row] = 0xffff;
            }
            else
            {
                row++;
                col = 0;
            }
        }
        
    }
    return solveQueen;
    
}