/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int dfs(TreeNode *root){
    if(root==NULL)
    return 0;
    if(!root->left)
    return 1+dfs(root->right);
    else if(!root->right)
    return 1+dfs(root->left);
    else
    return 1+min(dfs(root->left),dfs(root->right));
}
int Solution::minDepth(TreeNode* A) {
    return dfs(A);
}
