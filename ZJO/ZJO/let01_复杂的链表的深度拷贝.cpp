/*
 * @file   let01_���ӵ��������ȿ���.cpp
 * @date   2019.3.24.
 * @author GBW
 * @Description: ��֪һ�����������������һ��ָ����������ĳ���������ָ��(Ҳ����Ϊ��)��������������ȿ���
 
 * @Note:
 1. ��ȿ���:��������һ����ȫ�µ�������ʹ��ԭ����ٻ���������ɶ���ʹ��
 2. ��������ȿ����������
 3. ��ԭ��randomָ����߼���ϵ��������������֮��
 */
struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode (int x):label(x), next(NULL),random(NULL){}

};

RandomListNode* copyRandomList(RandomListNode* head)
{
	map<RandomListNode*, int> node_map; // ��ַ�����λ�õ�map
	vector<RandomListNode*> node_vec;  
	RandomListNode* ptr = head;         // ʹ��vector���ݴ洢���λ�÷��ʵ�ַ

	int i = 0;
	while (ptr)                        // ����������push��node_vec,��������������λ�õ���ַ��map
	{
		node_vec.push_back(new RandomListNode(ptr->label));
		node_map[ptr] = i;
		ptr = ptr->next;
		++i;
	}
	node_vec.push_back(0);

	ptr = head;
	i = 0; // �ٴα���ԭʼ�б� �����������nextָ�룬randomָ��
	while (ptr)
	{
		node_vec[i]->next = node_vec[i + 1];  // ����������nextָ��
		if (ptr->random)                      // ���ptr��random��Ϊ�գ���ô��ĸ�random��ָ��Ľ�㣬������ǰ���node_vec[i]ָ��random����ptr->random�Ľ��
		{
			int id = node_map[ptr->random];   // node_map[ptr->random] ����ֵ�Ƕ���???????????????????
			node_vec[i]->random = node_vec[id];
		}
		ptr = ptr->next;
		i++;
	}
	return node_vec[0];

}