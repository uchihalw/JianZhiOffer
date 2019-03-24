/*
 * @file   15.链表从位置m到n的逆序.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: 将链表从位置m到n逆序(不申请额外空间) 
 
 * @Note:
 
 */
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	int change_len = n - m + 1; // 计算要逆置的结点数
	ListNode* pre_head = NULL;  // 初始化开始逆置的结点的前驱
	ListNode* result = head;    // 最终转换后的链表的头结点
	while (head && --m)
	{
		pre_head = head;
		head = head->next;

	}
	ListNode* new_tail = head;   // 需要逆置部分的尾
	ListNode* new_head = NULL;   // 需要逆置部分的头
	while (head && change_len)
	{
		ListNode* next = head->next;
		head->next = new_head;
		new_head = head;
		head = next;
		change_len--;
	}
	new_tail->next = head;  // 连接逆置后的链表尾和第 n+1 个结点

	if (pre_head)           // 如果pre_head不空，说明不是从第一个结点开始逆置的 m > 1
	{
		pre_head->next = new_head;
	}
	else                    // 如果pre_head为空，说明m==1从第一个结点开始逆置
	{
		result = new_head;
	}
	return result;
}
