/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inOrder(TreeNode* root, vector<int>& temp){
    if(!root) return;
    
    inOrder(root->left, temp);
    temp.push_back(root->val);
    inOrder(root->right, temp);
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    inOrder(A, res);
    return res;
}
