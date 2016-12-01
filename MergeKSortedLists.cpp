#include <iostream>
#include <vector>
#include <limits.h>
#include <random>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode()
	{}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode  *res = NULL;
		ListNode  *p = res;
		ListNode  *q;
		lists.push_back(res);

		bool end = false;
		while(!end)
		{
			end = true;
			int tag = 0;
			int min = INT_MIN;
			for(int i = 0 ;i < lists.size()-1;i++)
			{
				if(lists[i] == NULL)
					continue;
				if(lists[i]->val >= min)
				{
					end = false;
					min = lists[i]->val;
					tag = i;
				}
			}
			if(!end)
			{
				q = lists[tag];
				lists[tag] = lists[tag]->next;
				q->next = NULL;
				if(p == NULL)
				{
					p = q;
					lists[lists.size()-1] = p;
				}else
				{
					p ->next = q;
					p = p->next;
				}
			}
		}
		return lists[lists.size()-1];
    }
};

int main()
{
	vector<ListNode *> nums ;
	int g = 10;
	for(int i = 0;i< g;i++)
	{
		nums.push_back(NULL);
	}
	int num = 0;
	for(int i = 0;i< 20000;i++)
	{
		num += rand() %10;
		int tag = rand() %g;
		if(nums[tag] == NULL)
		{
			ListNode *m = new ListNode();
			m->next = NULL;
			m->val = num;
			nums[tag] = m;
		}
		else{
			ListNode *m = new ListNode();
			m->val = num;
			m->next = nums[tag];
			nums[tag] = m;
		}
	}
	Solution s;
	s.mergeKLists(nums);
	ListNode *ss = nums[nums.size() -1];
	while(ss != NULL)
	{
		cout << ss->val << " ";
		ss = ss->next;
	}
	cout <<endl;
	return 0;
}
