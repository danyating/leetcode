//递归思想
//注意：递归分左右节点时需加上根节点1


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    int countNodes(TreeNode* root);
private:
    int leftHeight(TreeNode* left);
    int rightHeight(TreeNode* right);
};

int Solution::countNodes(TreeNode* root)
{
    int nodesNum;
    int lHeight = leftHeight(root);
    int rHeight = rightHeight(root);
    if(lHeight == rHeight)
    {
        nodesNum = (1 << lHeight) - 1;
    }
    else
    {
        nodesNum = countNodes(root->left) + countNodes(root->right) + 1;
    }
    return nodesNum;
}

int Solution::leftHeight(TreeNode* left)
{
    int lHeight = 0;
    while(NULL != left)
    {
        lHeight++;
        left = left->left;
    }
    return lHeight;
}

int Solution::rightHeight(TreeNode* right)
{
    int rHeight = 0;
    while(NULL != right)
    {
        rHeight++;
        right = right->right;
    }
    return rHeight;
    
}