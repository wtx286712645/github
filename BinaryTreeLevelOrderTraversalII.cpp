#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root)
	{
		vector<vector<int> > tem;
		OrderTras(root,0,tem);
		vector<vector<int> > result(tem.rbegin(),tem.rend());	
		return result;
	}

	void OrderTras(TreeNode *root,int depth,vector<vector<int> > &result)
	{
		if(root == NULL)
			return;
		if(depth >= result.size())	
		{
			vector<int> tem;
			tem.push_back(root->val);
			result.push_back(tem);
		}else
		{
			result[depth].push_back(root->val);
		}

		OrderTras(root->left,depth+1,result);
		OrderTras(root->right,depth+1,result);
	}
};

int main()
{
	Solution s;
	return 0;

}
