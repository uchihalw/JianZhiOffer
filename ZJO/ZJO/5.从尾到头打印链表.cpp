/*
 * @file   5.��β��ͷ��ӡ����.cpp
 * @date   2019.3.5.
 * @author GBW
 * @Description: ����һ�������ͷ��㣬��β��ͷ��������ӡÿ������ֵ
 
 * @Note:
	1.ȷ���Ƿ���Ըı�����Ľṹ
	2.�Ӻ���ǰ�����͵�"����ȳ�"��������ջ��ʵ��
	3.�ݹ�
	4.����͵�����
 */
#include<iostream>
#include<stack>
using namespace std;
typedef struct Node
{
	int data;
	struct Node* next;

}Node;



// ͷ�巨
Node*  createListHead()
{
	Node *head = NULL;
	Node *tmp = (Node*)malloc(sizeof(Node));

	while (scanf_s("%d", &tmp->data))
	{
		tmp->next = NULL;

		if (head == NULL)
			head = tmp;
		else
		{
			tmp->next = head;
			head = tmp;
		}
		tmp = (Node*)malloc(sizeof(Node));
	}
	free(tmp);
	return head;
}

// β�巨
Node* createListTail()
{
	Node *head = NULL, *tail = NULL;
	Node *tmp = (Node*)malloc(sizeof(Node));
	while (scanf_s("%d", &tmp->data))
	{
		tmp->next = NULL;
		if (head == NULL)
			head = tmp;
		else
			tail->next = tmp;
		tail = tmp;
		tmp = tmp = (Node*)malloc(sizeof(Node));
	}
	free(tmp);
	return head;
}


// �ͷ�����ռ�
void freeList(Node *head)
{
	Node *p;
	while (head)
	{
		p = head->next;
		free(head);
		head = p;
	}
}

void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << endl;
		head = head->next;
	}
}

// ���ɸı�����ṹ: ����ջ���
void printListTail2Head_stack(Node* head)
{
	stack<Node*> nodes;
	Node* tmp;
	while (head != NULL)
	{
		nodes.push(head);
		head = head->next;
	}
	while (!nodes.empty())
	{
		tmp = nodes.top();
		cout << tmp->data << endl;
		nodes.pop();
	}
}

// ���ɸı�����ṹ: �ݹ��ӡ
void printListTail2Head_recursion(Node* head)
{
	if (head->next == NULL)
		cout << head->data << endl;
	else
	{
		printListTail2Head_recursion(head->next);
		cout << head->data << endl;
	}

}



// �ɸı�����ṹ: �͵���������
void printListTail2Head_reverse(Node* head)
{
	Node* tmp1 = NULL, *tmp2 = NULL;
	tmp1 = head->next;
	tmp2 = tmp1->next;
	head->next = NULL;
	while (tmp2 != NULL)
	{

		tmp2 = tmp1->next;
		tmp1->next = head;
		head = tmp1;
		tmp1 = tmp2;
	}
}
