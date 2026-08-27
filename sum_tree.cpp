int sum_tree(TreeNode* root){
    if(root== NULL)
    return 0;

    int left_sum= sum_tree(root->left);
    int right_sum= sum_tree(root->right);
    root->val += left_sum+right_sum;
    return root->val;
}
