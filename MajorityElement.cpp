#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>


using namespace std;

class Solution{
	public:
		int majorityElement(vector<int> &num)
		{
			int len = num.size();
			int count = 1 ;
			int tem = num[0];
			for(int i = 1;i < len;i++)
			{
				if(count <= 0)
				{
					tem = num[i];
					count = 1;
				}
				if(tem = num[i])
					count++;
				else
					count--;
			}
			return tem;
		}
};



int main()
{
	Solution s;

	srand(time(0));

	vector<int> v;
	for(int i = 0;i < 100;i++)
	{
		v.push_back(rand()%100);
	}
	for(int i = 0;i<= 100;i++)
		v.push_back(50);
	for(int i = 0;i < v.size();i++)
		cout << v[i] << " ";
	cout << endl;

	cout << s.majorityElement(v) << endl;
	return 0;
}

