#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};


class Solution
{
public:
	vector<vector<int> >levelOrder(TreeNode *root)
	{
		vector<vector<int> > result;

		if(root == NULL)
			return result;

		vector<int> tem;
		tem.push_back(root->val);
		result.push_back(tem);
		
		int p = 0;	
	
		while(p < result.size())
		{
			tem.resize(0);
			for(int i = 0;i < result[p].size();i++)
			{
				tem.push_back(result[p][i]);
			}
			if(!tem.empty())
			{
				result.push_back(tem);
			}
			p++;
		}

	}
};
int main()
{
	Solution s;
	return 0;
}
