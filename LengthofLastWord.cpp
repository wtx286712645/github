#include <stdio.h>

using namespace std;

class Solution{
	public:
		int lengthOfLastWord(const char *s)
		{
			if(s == NULL)
				return 0;
			const char *p = s;
			int num_c = 0;
			int tem = 0;
			while(true)
			{
				if((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
				{
					tem++;
				}
				else
				{
					if(tem != 0)
						num_c = tem;
					tem = 0;
					if(*p == '\0')
						return num_c;
				}
				p++;
			}
		}
};

int main()
{
	Solution s;
	const char a[] = "a";
	printf("%d",s.lengthOfLastWord(a));
}
