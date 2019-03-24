/*
 * @file   let01_复杂的链表的深度拷贝.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: 已知一个复杂链表，结点中有一个指向本链表任意某个结点的随机指针(也可以为空)，求这个链表的深度拷贝
 
 * @Note:
 1. 深度拷贝:构造生成一个完全新的链表，即使将原链表毁坏，新链表可独立使用
 2. 返回是深度拷贝后的链表
 3. 将原来random指针的逻辑关系，拷贝到新链表之中
 */
struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode (int x):label(x), next(NULL),random(NULL){}

};

RandomListNode* copyRandomList(RandomListNode* head)
{
	map<RandomListNode*, int> node_map; // 地址到结点位置的map
	vector<RandomListNode*> node_vec;  
	RandomListNode* ptr = head;         // 使用vector根据存储结点位置访问地址

	int i = 0;
	while (ptr)                        // 将新链表结点push入node_vec,生成了新链表结点位置到地址的map
	{
		node_vec.push_back(new RandomListNode(ptr->label));
		node_map[ptr] = i;
		ptr = ptr->next;
		++i;
	}
	node_vec.push_back(0);

	ptr = head;
	i = 0; // 再次遍历原始列表 连接新链表的next指针，random指针
	while (ptr)
	{
		node_vec[i]->next = node_vec[i + 1];  // 连接新链表next指针
		if (ptr->random)                      // 如果ptr的random不为空，那么求的该random所指向的结点，并将当前结点node_vec[i]指向random等于ptr->random的结点
		{
			int id = node_map[ptr->random];   // node_map[ptr->random] 返回值是多少???????????????????
			node_vec[i]->random = node_vec[id];
		}
		ptr = ptr->next;
		i++;
	}
	return node_vec[0];

}