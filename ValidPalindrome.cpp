#include <iostream>
#include <string>

using namespace std;

class Solution{
	public:
		bool isPalindrome(string s)
		{
			if(s.empty())
				return true;
			string tem;
			for(int i = 0;i < s.length();i++)
			{
				if((s[i]>= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))
					tem.push_back(s[i]);
				else if(s[i] >= 'A' && s[i] <= 'Z')
					tem.push_back(s[i] + ('a'-'A'));
			}
			int back = tem.length() - 1;
			int pre = 0;
			while(pre < back)
			{
				if(tem[pre] != tem[back])
					return false;
				pre++;
				back--;
			}
			return true;
		}
};

int main()
{
	Solution s;
	s.isPalindrome("alskjdfl23098HHafO9lj;rjousdf20139483248*12");
	cout << ("alskjdfl23098HHafO9lj;rjousdf20139483248*12") << endl;
	return 0;	
}
