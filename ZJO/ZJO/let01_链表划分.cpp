/*
 * @file   let01_������.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: ��֪����ͷָ��head������x��������С��x�Ľ����ڴ��ڻ����x�Ľ��ǰ���ұ�����Щ����ԭ�������λ��
 
 * @Note:
 
 */

// version_0 . ������ʱͷ���
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
