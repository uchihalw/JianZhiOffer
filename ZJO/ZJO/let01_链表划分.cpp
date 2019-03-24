/*
 * @file   let01_链表划分.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: 已知链表头指针head与数组x，将所有小于x的结点放在大于或等于x的结点前，且保持这些结点的原来的相对位置
 
 * @Note:
 
 */

// version_0 . 巧用临时头结点
ListNode* partition(ListNode* head, int x)
{
	ListNode* less_head = new ListNode();
	ListNode* more_head = new ListNode();
	ListNode* less_ptr = less_head;
	ListNode* more_ptr = more_head;
	while (head)
	{
		if (head->val < = )
		{
			less_ptr->next = head;
			less_ptr = hea;
		}
		else
		{
			more_ptr->next = head;
			more_ptr = head;
		}
		head = head->next;
	}
	less_ptr->next = more_head->next;
	more_ptr->next = NULL;
	return less_head->next;
}
