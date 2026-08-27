class Solution {
public:
    TreeNode* prev = NULL;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)
        return INT_MAX;

        int ans= INT_MAX;
        if(root->left)
        {
            int left_min = minDiffInBST(root->left);
            ans= min(ans,left_min);
        }
        if(prev!=NULL)
        {
            ans= min(ans, root->val - prev->val);
        }
        prev=root;
        if(root->right)
        {
            int right_min = minDiffInBST(root->right);
            ans= min(ans,right_min);
        }
        return ans;
    }
};
