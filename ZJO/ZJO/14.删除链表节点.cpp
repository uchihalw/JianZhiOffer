/*
 * @file   14.删除链表节点.cpp
 * @date   2019.3.21.
 * @author GBW
 * @Description: 
 
 * @Note:
 
 */
0. 把结点j的内容复制覆盖结点i,接下来再把结点i的next指向j的下一个结点，然后删除结点j。这种方法不用遍历链表上
结点i前面的结点。

1. 此代码基于:假设要删除的结点的确在链表中。否则我们需要O(n)的时间才能判断链表中是否包含将要删除的结点
void DeleteNode(ListNode** pListHead, ListNode* PToBeDeleted)
{
	if (!pListHead || !PToBeDeleted)
		return;

	// 要删除的结点(PToBeDeleted)不是尾结点
	if (PToBeDeleted->next!= NULL)
	{
		ListNode* pNext = PToBeDeleted->next;
		PToBeDeleted->value = pNext->value;
		PToBeDeleted->next = pNext->next;
		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == PToBeDeleted) // 链表只有一个结点(PToBeDeleted)，删除头结点(也是尾结点)
	{
		delete PToBeDeleted;
		PToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else // 链表中有多个结点，删除尾结点(PToBeDeleted)
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