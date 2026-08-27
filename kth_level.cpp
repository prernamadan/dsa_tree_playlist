void kth_level(TreeNode* root,int k)
{
    if(root== NULL)
    return;
    
    if(k==1)
    {
        cout<<root->val;
        return;
    }
    kth_level(root->left, k-1);
    kth_level(root->right, k-1);
}
