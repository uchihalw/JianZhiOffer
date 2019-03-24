/*
 * @file   let01_多个排序链表的合并.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: 已知k个已排序链表头结点指针，将这k个链表合并，合并后仍为有序的，返回合并后的头结点
 
 * @Note:
 
 */

// version_0
// 最普通的方法，k个链表按顺序合并k-1次。 O(K^2*N)


// version_1
// 将k*n个结点放到vector中，再将vector排序，再将结点顺序相连
bool cmp(const ListNode* a, const ListNode* b)
{
	return a->val < b->val;
}
ListNode* mergeKList(vector<ListNode*>& lists)
{
	vector<ListNode*> node_vec;
	for (int i = 0; i < lists.size(); i++)
	{
		ListNode* head = lists[i];              // 遍历k个链表，将结点全部添加至node_vec
		while (head)
		{
			node_vec.push_back(head);
			head = head->next;

		}
	}
	if (node_vec.size() == 0)
		return NULL;

	sort(node_vec.begin(), node_vec.end(), cmp);

	for (int i = 0; i < node_vec.size(); i++)
		node_vec[i - 1]->next = node_vec[i];

	node_vec[node_vec.size() - 1]->next = NULL;
	return node_vecp[0];

}


// version_2
// 对k个链表进行分治，两两进行合并。  O(KNlogK)
ListNode* mergeKList(vector<ListNode*>& lists)
{
	if (lists.size() == 0)
		return NULL;
	if (lists.size() == 1)
		return lists[0];

	if (lists.size() == 2)
		mergeTwoLists(lists[0], lists[1]);

	int mid = lists.size() / 2;
	vector<ListNode*> sub1_lists;
	vector<ListNode*> sub2_lists;

	for (int i = 0; i < mid; i++)
	{
		sub1_lists.push_back(lists[i]);
	}
	for (int j = 0; j < lists.size(); j++)
	{
		sub1_lists.push_back(lists[j]);
	}

	ListNode* L1 = mergeKLists(sub1_lists);
	ListNode* L2 = mergeKLists(sub1_lists);
	return mergeTwoLists(L1, L2);            // 分治处理

}






































