/*
 * @file   let01_排序链表的合并.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: 已知两个已排序链表头结点指针L1和L2,将这两个链表合并，合并后仍为有序的，返回合并后的头结点
 
 * @Note:
 预设临时头结点，比较L1和L2指向的结点，将较小的结点插入到pre指针后，并向前异地欧冠较小结点对应的指针
 */
ListNode* mergeTwoLists(ListNode* L1, ListNode* L2)
{
	ListNode* temp_head = new ListNode();
	ListNode* tail = temp_head;
	while (L1 && L2)
	{
		if (L1->val < L2->val)
		{
			tail->next = L1;
			L1 = L1->next;
		}
		else
		{
			tail->next = L2;
			L2 = L2->next;
		}
		tail = tail->next;
	}
	if (L1)
	{
		tail->next = L1;
	}
	if (L2)
	{
		tail->next = L2;
	}
	return temp_head->next;
}
