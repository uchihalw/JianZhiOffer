/*
 * @file   15.�����λ��m��n������.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: �������λ��m��n����(���������ռ�) 
 
 * @Note:
 
 */
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	int change_len = n - m + 1; // ����Ҫ���õĽ����
	ListNode* pre_head = NULL;  // ��ʼ����ʼ���õĽ���ǰ��
	ListNode* result = head;    // ����ת����������ͷ���
	while (head && --m)
	{
		pre_head = head;
		head = head->next;

	}
	ListNode* new_tail = head;   // ��Ҫ���ò��ֵ�β
	ListNode* new_head = NULL;   // ��Ҫ���ò��ֵ�ͷ
	while (head && change_len)
	{
		ListNode* next = head->next;
		head->next = new_head;
		new_head = head;
		head = next;
		change_len--;
	}
	new_tail->next = head;  // �������ú������β�͵� n+1 �����

	if (pre_head)           // ���pre_head���գ�˵�����Ǵӵ�һ����㿪ʼ���õ� m > 1
	{
		pre_head->next = new_head;
	}
	else                    // ���pre_headΪ�գ�˵��m==1�ӵ�һ����㿪ʼ����
	{
		result = new_head;
	}
	return result;
}
