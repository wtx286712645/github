#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		vector<int> plusOne(vector<int> &digits)
		{
			int carry = 1;
			int i;	

			for(i = 0;i < digits.size();i++)
			{
				if(digits[i] == 9)
					continue;
				else
					break;
			}

			cout << digits.size() << endl;

			if(i == digits.size())
			{
				vector<int> result(digits.size() + 1,0);
				result[0] = 1;
				return result;
			}

			for(int i = digits.size() -1;i >= 0;i--)
			{
				if(digits[i] == 9 && carry == 1)
				{
					digits[i] = 0;
					continue;
				}else
				{
					digits[i]++;
					break;
				}
			}
			return digits;
		}
};

int main()
{

	Solution s;
	while(1)
	{
		vector<int> v;
		int num,count;
		cout << "input the count of nums" << endl;
		cin >>count;
		for(int i = 0;i < count;i++)
		{

			cin >> num;
			v.push_back(num);
		}
		vector<int> v2 = s.plusOne(v);
		for(int i = 0;i < v2.size();i++)
		{
			cout << v2[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
