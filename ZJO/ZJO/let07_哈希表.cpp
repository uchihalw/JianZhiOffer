/*
 * @file   let07_¹şÏ£±í.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: 
 
 * @Note:
 
 */
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
int hash_func(int key, int table_len)
{
	return key % table_len;
}
void insert(ListNode *hash_table[], ListNode* node, int table_len)
{
	int hash_key = hash_func(node->val, table_len);
	node->next = hash_table[hash_key]; // Í·²å·¨
	hash_table[hash_key] = node;
}
bool search(ListNode* hash_table[], int value, int table_len)
{
	int hash_key = hash_func(value, table_len);
	ListNode* head = hash_table[hash_key];
	while (head)
	{
		if (head->val == value)
			return true;
		head = head->next;
	}
	return false;
}