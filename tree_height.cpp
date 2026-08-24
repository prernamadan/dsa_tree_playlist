int height(Node* root){
    if (root==NULL)
    return 0 ;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return max(left_height,right_height)+1;


}
