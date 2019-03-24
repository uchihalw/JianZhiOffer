/*
 * @file   let01_链表求环.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: 已知链表中可能存在环，若有环返回环起始结点，否则返回NULL
 
 * @Note:
 
 */


// version_1
/*
1.遍历链表，将链表找那个结点对应的指针(地址)，插入set
2.在遍历插入结点前，需要在set中查找，第一个在set中发现的结点地址，即是链表环的起点
*/
ListNode* detectCycle(ListNode *head)
{
	set<ListNode *> node_set;
	while (head)
	{
		if (node_set.find(head) != node_set.end())
			return head;
		node_set.insert(head);
		head = head->next;
	}
	return NULL;
}

// version_2
/*
0.快慢指针跑
1.慢指针一次一步
2.快指针一次两步
3.结论:从head与meet(快慢指针相遇)出发，两指针速度一样，相遇时即为环的起点
*/
ListNode *detecCycle(ListNode *head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* meet = NULL;

	while (fast)
	{
		slow = slow->next;
		fast = fast->next;

		if (!fast)           // head只有一个结点
			return NULL;
		fast = fast->next;
		if (slow = fast)
		{
			meet = fast;
			break;
		}
	}
	if (meet == NULL)
		return NULL;
	while (head && meet)   // distance(head,相遇点) == distance(meet, 相遇点)
	{
		if (head == meet)
			return head;
		head = head->next;
		meet = meet->next;
	}
}





















