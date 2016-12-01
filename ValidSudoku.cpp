#include <iostream>

#include <vector>


using namespace std;

class Solution{
	public:
		bool isValidSudoku(vector<vector<char> > &board)
		{
			for(int i = 0;i < board.size();i++)
			{
				vector<int> tool(9,0);
				for(int j = 0;j < board.size();j++)
				{
					if(board[i][j] != '.')
					{
						if(	tool[board[i][j] - '0'-1])
						{
							return false;
						}
						else
						{
							tool[board[i][j]- '0'-1]++;
						}
					}
				}
			}

			for(int i = 0;i < board.size();i++)
			{
				vector<int> tool(9,0);
				for(int j = 0;j < board.size();j++)
				{
					if(board[j][i] != '.')
					{
						if(tool[board[j][i] - '0' - 1])
						{
							return false;
						}
						else
						{
							tool[board[j][i]- '0' - 1]++;
						}
					}
				}
			}
			
			for(int i = 0;i < 3;i++)
			{
				for(int j = 0;j < 3;j++)
				{
					int r_pre = 3 * i;
					int c_pre = 3 * j; 
					vector<int> tool(9,0);
					for(int ii = 0;ii < 3;ii++)
					{
						for(int jj = 0;jj < 3;jj++)
						{	
							if(board[r_pre + ii][c_pre + jj] != '.')
							{
								char c = board[r_pre + ii][c_pre + jj];
								if(tool[board[r_pre + ii][c_pre + jj] - '0' - 1])
									return false;
								else
									tool[board[r_pre + ii][c_pre + jj]- '0' - 1]++;
							}
						}
					}
				}
			}
			return true;
		}
};

int main()
{

	Solution s;
	vector<vector<char> > sudo;
	for(int i = 0;i < 9;i++)
	{
		vector<char> tem;
		for(int j = 0;j < 9;j++)
		{
			char c;
			cin >> c;
			tem.push_back(c);
		}
		sudo.push_back(tem);
		cout << endl;
	}
	if(s.isValidSudoku(sudo))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
