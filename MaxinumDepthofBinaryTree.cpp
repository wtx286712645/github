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
	int maxDepth(TreeNode *root)
	{
		if(root == NULL)
			return 0;
		int depth_left = maxDepth(root->left);
		int depth_right = maxDepth(root->right);
		return (depth_left>depth_right) ?depth_left+1:depth_right+1;
	}
};

int main()
{
	Solution s;
	return 0;

}
