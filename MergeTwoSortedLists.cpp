#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution{
	public:
		ListNode *mergeTwoLists(ListNode *l1,ListNode *l2){
			ListNode *newlist = NULL;
			if(l1 == NULL)
				return l2;
			if(l2 == NULL)
				return l1;

			ListNode *p = l1,*q = l2;
			if(l1->val < l2->val)
			{
				newlist = p;
				p = p->next;
			}else
			{
				newlist = l2;
				q = q->next;
			}
			ListNode *k = newlist;
			while(p != NULL && q != NULL)
			{
				if(p->val < q->val)
				{
					k->next = p;
					k = k-next;
					p = p->next;
				}else
				{
					k->next = q;
					k = k-next;
					q = q->next;
				}

			}
			if(p!= NULL)
				k->next = p;
			if(q != NULL)
				k->next = q;
			return newlist;
		}
};
int main()
{ 
	Solution s;

}
