/*
 * @file   let01_����������Ľ���.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: ��֪����A��ͷ���ָ��headA������B��ͷ���ָ��headB�����������ཻ�����������Ӧ�Ľ��㡣
 
 * @Note:
 1. �����������û�н��㣬�򷵻�NULL
 2. ���󽻵�Ĺ����У��������ƻ�����Ľṹ�����޸������������
 3. ����ȷ�����������û���κλ�
 */

// version_0
void findNode(int *a, int *b, int aLen, int bLen)
{
	set<int> test_set;

	for (int i = 0; i < aLen; i++)
	{
		test_set.insert(a[i]); // ������a��Ԫ�ز���set
	}

	for (i = 0; i < bLen; i++)
	{
		if (test_set.find(b[i] != test_set.end()))   // ��test_set�в���b[i]��ֱ��test_set��end
			printf("b[%d] = %d in array a.\n", i, b[i]);
	}
}


// version_1
/*
1. ��������A,��A�н���Ӧ��ָ���ַ������set
2. ��������B,��B�н���Ӧ��ָ���ַ����set�в��ң�������set�е�һ������ַ��������������Ľ���
*/

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
{
	set<ListNode*> node_set;
	while (headA)
	{
		node_set.insert(headA);
		headA = headA->next;
	}
	while (headB)
	{
		if (node_set.find(headB) != node_set.end())
			return headB;
		headB = headB->next;
	}
	return NULL;
}

// version_2
/*
1. ����headA�������ȣ�����headB����ĳ��ȣ��ϳ����������ĳ���
2. ���ϳ������ָ���ƶ����ͽ϶�����ָ������λ��
3. headA��headBͬʱ�ƶ�������ָ��ָ��ͬһ�����ʱ�����Ҵ�
*/
int get_list_length(ListNode* head)
{
	int len = 0;
	while (head)
	{
		++len;
		head = head->next;
	}
}


ListNode* forward_long_list(int long_len, int short_len, ListNode *long_head)
{
	int delta = long_len - short_len;
	while (head &&delta)
	{
		head = head->next;
		--delta;
	}
	return head;
}

ListNode* getInsertionNode(ListNode *headA, ListNode *headB)
{
	int List_A = get_list_length(headA);
	int List_B = get_list_length(headB);

	if (List_A > List_B)
		forward_long_list(List_A, List_B, headA);
	else
		forward_long_list(List_B, List_A, headB);

	while (headA && headB)
	{
		if (headA == headB)
			return headA;
		headA = headA->next;
		headB = headB->next;
	}
	return NULL;
}