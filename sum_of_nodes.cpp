int sum_nodes(Node* root){
    if (root==NULL)
    return 0 ;
    int left_sum = sum_nodes(root->left);
    int right_sum = sum_nodes(root->right);
    return left_sum+right_sum+ root->data;

}
