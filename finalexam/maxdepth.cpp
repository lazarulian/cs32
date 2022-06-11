int maxDepth(Node *root)
{
    if (root == nullptr)
        return -1;
    // computer depth of each subtree int lDepth = maxDepth(root->left); int rDepth = maxDepth(root->right);
    // return the max of the two if (lDepth > rDepth)
    return lDepth + 1;
    else return rDepth + 1;
}