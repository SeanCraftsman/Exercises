#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root == NULL){
            sum = 0;
        }
        else if(root->left != NULL){
            if(root->left->left == NULL && root->left->right == NULL){
                sum += root->left->val;
            }
            sum += (sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right));
        }
        else{
            sum = sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};

int main(){
    TreeNode a3 = TreeNode(3);
    TreeNode a9 = TreeNode(9);
    TreeNode a20 = TreeNode(20);
    TreeNode a15 = TreeNode(15);
    TreeNode a7 = TreeNode(7);
    a3.left = &a9;
    a3.right = &a20;
    a20.left = &a15;
    a20.right = &a7;

    Solution s;
    cout << s.sumOfLeftLeaves(&a3) << endl;
    return 0;
}
