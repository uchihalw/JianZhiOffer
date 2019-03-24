/*
 * @file   let01_��������ĺϲ�.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: ��֪��������������ͷ���ָ��L1��L2,������������ϲ����ϲ�����Ϊ����ģ����غϲ����ͷ���
 
 * @Note:
 Ԥ����ʱͷ��㣬�Ƚ�L1��L2ָ��Ľ�㣬����С�Ľ����뵽preָ��󣬲���ǰ���ŷ�ڽ�С����Ӧ��ָ��
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
