vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> res;
    if (A == NULL) return res;

    stack<TreeNode*> s1, s2;
    s1.push(A);

    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children to s1
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    // Pop all elements from s2 to get the postorder traversal
    while (!s2.empty()) {
        res.push_back(s2.top()->val);
        s2.pop();
    }

    return res;
}
