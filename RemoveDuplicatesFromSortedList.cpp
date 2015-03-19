#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
	public:
		ListNode *deleteDuplicates(ListNode *head)
		{
			if(head == NULL || head->next == NULL)
				return head;
			ListNode *p = head,*q = head->next;
			while(p != NULL)
			{
				while(q != NULL && q->val == p->val)
				{
					q = q->next;
				}
				p->next = q;
				p = q;
				if(p != NULL)
				    q = p->next;
			}
			return head;
		}
};

int main()
{

}
