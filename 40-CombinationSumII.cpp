using namespace std;
class Solution {
private:
    
    void recursive(int pos, int sum, int target, vector<int> &one, vector<int> &candidates);
public:
    vector<vector<int> > all;
    
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target);
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
            recursive(i + 1, sum, target, one, candidates);
            one.pop_back();
        }
        sum -= candidates[i];
        //除去重复的，与上题区别！！ 这个数组里面可能有重复的
        while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
        {
            i++;
        }
    }
}

vector<vector<int> > Solution::combinationSum2(vector<int> &candidates, int target)
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