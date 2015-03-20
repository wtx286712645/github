#include <iostream>

using namespace std;

class Solution{
	public:
	string addBinary(string a,string b)
	{
		int len_a = a.length();
		int len_b = b.length();

		if(len_a == 0)
			return b;
		else if(len_b == 0)
			return a;

		char carry_bit = '0';
		int i = len_a - 1,j = len_b - 1;
		
		string result;

		while(i >= 0 || j>= 0)
		{
			if(i < 0)
			{
				result = count('0',b[j],carry_bit) + result;
				j--;
				continue;
			}
			if(j < 0)
			{
				result = count(a[i],'0',carry_bit) + result;
				i--;
				continue;
			}
			result = count(a[i],b[j],carry_bit) + result;
			i--;
			j--;
		}
		if(carry_bit == '1')
			result = "1" + result;
		for(int i = 0;i < result.length();i++)
		{
			if(result[i] == '0' && i != result.length() - 1)
				continue;
			else
			{
				string tem(result.begin() + i,result.end());
				result = tem;
				break;
			}
		}
		return result;
	}
	string count(char a,char b,char &c)
	{
		int b_a = (a == '0')? 0:1;
		int b_b = (b == '0')? 0:1;
		int b_c = (c == '0')? 0:1;

		string s_result;
		int result = b_a + b_b + b_c;
		switch(result)
		{
			case 0: c = '0';
					s_result = "0";
					break;
			case 1: c = '0';
					s_result = "1";
					break;
			case 2: c = '1';
					s_result = "0";
					break;
			case 3: c = '1';
					s_result = "1";
					break;
		}
		return s_result;
	}

};

int main()
{
	Solution s;
	while(1)
	{
		string s1,s2;
		cin >> s1 >> s2;
		cout <<	s.addBinary(s1,s2);
	}
	return 0;
}
