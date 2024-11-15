/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void pre(TreeNode* root, vector<int>& temp){
     if(!root) return;
     
     temp.push_back(root->val);
     pre(root->left, temp);
     pre(root->right, temp);
 }
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> res;
    pre(A, res);
    return res;
}
