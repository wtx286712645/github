#include <iostream>

using namespace std;

class Solution{
	public:
		void merge(int A[],int m,int B[],int n)
	{
		if(m < 0 || n < 0)
			return;
		int i = m + n -1;
		int p = m - 1;
		int q = n - 1;

		while(q >= 0)
		{
			if(B[q] > A[p] || p < 0)
			{
				A[i] = B[q];
				q--;
			}
			else
			{
				A[i] = A[p];
				p--;
			}
			i--;

		}
	}
};

int main()
{
	int A[100] = {3,4,12,23,34,56,67,78,100};
	int B[4] = {1,2,3,35};
	Solution s;
	s.merge(A,9,B,4);
	for(int i = 0;i < 13;i++)
		cout << A[i] << "  ";
	return 0;

}
