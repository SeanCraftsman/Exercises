#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
	TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root){
	if(root == NULL){
		return 0;
	}
	else{
		int a = maxDepth(root->left);
		int b = maxDepth(root->right);
		return a > b ? a+1:b+1;
	}
}

int main(){
	TreeNode a = TreeNode(0);
	a.left = &TreeNode(1);
	a.right = &TreeNode(1);
	a.left->left = &TreeNode(2);
	a.left->left->left = &TreeNode(3);
	cout << maxDepth( &a ) << endl;
	return 0;
}