bool identical_tree(Node*p , Node* q)
{
    if(p==NULL || q==NULL)
    return p==q;
    bool left_identical= identical_tree(p->left, q->left);
    bool right_identical= identical_tree(p->right, q->right);

    return left_identical && right_identical && p->data==q->data;
}


bool check_subtree(Node* root, Node* subroot){

    if(root== NULL || subroot == NULL){
        return root== subroot;
    }

    if (root->data == subroot->data && identical_tree(root, subroot))
    return true;

    return check_subtree(root->left, subroot)|| check_subtree(root->right, subroot);
}
