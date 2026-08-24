int idx= -1;
Node* buildtree(vector<int> preorder){
    idx++;
    if(preorder[idx]== -1)
    return NULL;
    Node* root = new Node(preorder[idx]);
    root->left= buildtree(preorder);
    root->right= buildtree(preorder);

    return root;


}
