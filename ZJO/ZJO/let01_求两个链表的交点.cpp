/*
 * @file   let01_求两个链表的交点.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: 已知链表A的头结点指针headA，链表B的头结点指针headB，两个链表相交，求两链表对应的交点。
 
 * @Note:
 1. 如果两个链表没有交点，则返回NULL
 2. 在求交点的过程中，不可以破坏链表的结构或者修改链表的数据域
 3. 可以确保传入的链表没有任何环
 */

// version_0
void findNode(int *a, int *b, int aLen, int bLen)
{
	set<int> test_set;

	for (int i = 0; i < aLen; i++)
	{
		test_set.insert(a[i]); // 将数组a的元素插入set
	}

	for (i = 0; i < bLen; i++)
	{
		if (test_set.find(b[i] != test_set.end()))   // 在test_set中查找b[i]，直到test_set的end
			printf("b[%d] = %d in array a.\n", i, b[i]);
	}
}


// version_1
/*
1. 遍历链表A,将A中结点对应的指针地址，插入set
2. 遍历链表B,将B中结点对应的指针地址，在set中查找，发现在set中第一个结点地址，即是两个链表的交点
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
1. 计算headA的链表长度，计算headB链表的长度，较长的链表多出的长度
2. 将较长链表的指针移动到和较短链表指针对齐的位置
3. headA和headB同时移动，当两指针指向同一个结点时，即找打
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