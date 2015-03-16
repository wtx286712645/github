#include <iostream>
#include <string>

using namespace std;

class Solution{
	public:
		string convertToTitle(int n)
		{
			int cs = 1;
			string result;
			int tem_n = n;

			while(n / cs)
			{
				int tem = n/cs%26;
				if(tem == 0)
				{
					n -= 26;	
					char c[] = {'Z','\0'};
					result = string(c) + result;
				}
				else
				{
					char c[] = {'A' + tem - 1,'\0'};
					n -= (tem * cs);
					result = string(c) + result;
				}
				
				cs *= 26;
				
			}
			return result;
		}
};


int main()
{
	Solution s;
	for(int i = 1;i < 100;i++)
	cout<< i <<	s.convertToTitle(i)<< endl;
	return 0;
}
