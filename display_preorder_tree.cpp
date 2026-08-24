void display (Node* root){

    if(root==NULL)
    return;

    cout<<root->data<<"--";
    display(root->left);
    display(root->right);
}
