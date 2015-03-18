#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
struct TreeNode
{
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x):val(x),left(NULL),right(NULL){};
};
TreeNode *randTree(int nodeNum)
{
	if(nodeNum <= 0)
		return NULL;
	--nodeNum;
	TreeNode *root = new TreeNode(rand());
	root->val = rand() % 100;
	int leftnum = nodeNum *(root->val)/100;
	int rightnum = nodeNum - leftnum;
	root->left = randTree(leftnum);
	root->right = randTree(rightnum);
	return root;
}
class Solution
{
public:
	vector<vector<int> >levelOrder(TreeNode *root)
	{
		vector<vector<int> > result;
	
		if(root == NULL)
			return result;

		vector<vector<TreeNode *> > nodes;
		vector<TreeNode *> tem;
		vector<int> temInt;
	
		tem.push_back(root);
		nodes.push_back(tem);
		temInt.push_back(root->val);
		result.push_back(temInt);
		int p = 0;
		while(p < result.size())
		{
			tem.resize(0);
			temInt.resize(0);
			for(int i = 0;i < nodes[p].size();i++)
			{
				if(nodes[p][i]->left)
				{
					tem.push_back(nodes[p][i]->left);
					temInt.push_back(nodes[p][i]->left->val);
				}
				if(nodes[p][i]->right)
				{
					tem.push_back(nodes[p][i]->right);
					temInt.push_back(nodes[p][i]->right->val);
				}	
			}
			if(!tem.empty())
			{
				nodes.push_back(tem);
				result.push_back(temInt);
			}
			int size = result.size();
			p++;
		}
		return result;
	}
};
int main()
{
	srand(time(0));
	TreeNode *tree = randTree(20);
	Solution s;
	s.levelOrder(tree);
	return 0;
}
