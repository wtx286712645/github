#include <iostream>

using namespace std;

class Solution{
public:
/*	int climbStairs(int n)
	{
		if(n == 0)
			return 0;
		if(n == 1)
			return 1;
		if(n == 2)
			return 2;
		return climbStairs(n - 1) + climbStairs(n - 2);
	}
	*/
	int climbStairs(int n)
	{
		if(n == 0)
			return 0;
		if(n == 1)
			return 1;
		if(n == 2)
			return 2;
		int first = 1;
		int second = 2;

		int result;
		for(int i = 3;i <= n;i++)
		{
			result = first + second;
			first = second;
			second = result;
		}
		return result;
	}
};
int main()
{
	while(1)
	{
		Solution s;
		int n;
		cin >> n;
		cout <<	s.climbStairs(n);
	}
}
