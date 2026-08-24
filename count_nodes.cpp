int count_nodes(Node* root){
    if (root==NULL)
    return 0 ;
    int count_left = count_nodes(root->left);
    int count_right = count_nodes(root->right);
    return count_left+count_right+1;
}
