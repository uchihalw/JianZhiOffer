/*
 * @file   14.ɾ������ڵ�.cpp
 * @date   2019.3.21.
 * @author GBW
 * @Description: 
 
 * @Note:
 
 */
0. �ѽ��j�����ݸ��Ƹ��ǽ��i,�������ٰѽ��i��nextָ��j����һ����㣬Ȼ��ɾ�����j�����ַ������ñ���������
���iǰ��Ľ�㡣

1. �˴������:����Ҫɾ���Ľ���ȷ�������С�����������ҪO(n)��ʱ������ж��������Ƿ������Ҫɾ���Ľ��
void DeleteNode(ListNode** pListHead, ListNode* PToBeDeleted)
{
	if (!pListHead || !PToBeDeleted)
		return;

	// Ҫɾ���Ľ��(PToBeDeleted)����β���
	if (PToBeDeleted->next!= NULL)
	{
		ListNode* pNext = PToBeDeleted->next;
		PToBeDeleted->value = pNext->value;
		PToBeDeleted->next = pNext->next;
		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == PToBeDeleted) // ����ֻ��һ�����(PToBeDeleted)��ɾ��ͷ���(Ҳ��β���)
	{
		delete PToBeDeleted;
		PToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else // �������ж����㣬ɾ��β���(PToBeDeleted)
	{
		ListNode* pNode = *pListHead;
		while (pNode->next != PToBeDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = NULL;
		delete PToBeDeleted;
		PToBeDeleted = NULL;

	}

}