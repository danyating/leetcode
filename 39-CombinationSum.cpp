using namespace std;
class Solution {
private:
    
    void recursive(int pos, int sum, int target, vector<int> &one, vector<int> &candidates);
public:
    vector<vector<int> > all;
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target);
};

void Solution::recursive(int pos, int sum, int target, vector<int> &one, vector<int> &candidates)
{
    int i,j;
    if(sum == target)
    {
        all.push_back(one);
        return;
    }
    if(pos >= candidates.size())
    {
        return;
    }
    for(i = pos; i < candidates.size(); i++)
    {
        sum += candidates[i];
        if(sum <= target)
        {
            one.push_back(candidates[i]);
            recursive(i, sum, target, one, candidates);
            one.pop_back();
        }
        sum -= candidates[i];
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &candidates, int target)
{
    int i,j;
    int sum = 0;
    vector<int> one;
    if(0 == candidates.size())
    {
        return all;
    }
    sort(candidates.begin(), candidates.end());
    recursive(0, 0, target, one, candidates);
    return all;
    
    
}