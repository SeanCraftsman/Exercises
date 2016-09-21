#include <iostream>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root){
    TreeNode* temp;
    if(root != NULL){
        temp = root->left;
        root->left = invertTree(root->left);
        root->right = invertTree(temp);
    }
    return root;
}

int main(){
    TreeNode* a = &TreeNode(4);
    a->left = &TreeNode(2);
    a->right = &TreeNode(7);
    a->left->left = &TreeNode(1);
    a->left->right = &TreeNode(3);
    a->right->left = &TreeNode(6);
    a->right->right = &TreeNode(9);

    return 0;
}
