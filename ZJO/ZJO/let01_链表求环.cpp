/*
 * @file   let01_������.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: ��֪�����п��ܴ��ڻ������л����ػ���ʼ��㣬���򷵻�NULL
 
 * @Note:
 
 */


// version_1
/*
1.�����������������Ǹ�����Ӧ��ָ��(��ַ)������set
2.�ڱ���������ǰ����Ҫ��set�в��ң���һ����set�з��ֵĽ���ַ���������������
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
0.����ָ����
1.��ָ��һ��һ��
2.��ָ��һ������
3.����:��head��meet(����ָ������)��������ָ���ٶ�һ��������ʱ��Ϊ�������
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

		if (!fast)           // headֻ��һ�����
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
	while (head && meet)   // distance(head,������) == distance(meet, ������)
	{
		if (head == meet)
			return head;
		head = head->next;
		meet = meet->next;
	}
}





















