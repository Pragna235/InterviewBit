/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(!A) return ans;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i=0;i<n;i++){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
