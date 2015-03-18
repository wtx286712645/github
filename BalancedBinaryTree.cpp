#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
	public:
		bool isBalanced(TreeNode *root){
			bool isbalanced = true;
			depthOfTree(root,isbalanced);
			return isbalanced;
		}
	int depthOfTree(TreeNode *root,bool &isbalanced)
	{
		if(root == NULL)
			return 0;
		int leftDep = 0;
		int rightDep = 0;
		bool leftban = true;
		bool rightban = true;
		if(root->left != NULL)
			leftDep = depthOfTree(root->left,leftban);
		if(root->right !=NULL)
			rightDep = depthOfTree(root->right,rightban);
		int dis = leftDep - rightDep;
		if(dis < -1 || dis > 1)	
			isbalanced = false;
		else
			isbalanced = leftban && rightban;
		if(leftDep > rightDep)
			return leftDep + 1;
		else
			return rightDep + 1;
	}
};

int main()
{
	Solution s;
	return 0;
}
