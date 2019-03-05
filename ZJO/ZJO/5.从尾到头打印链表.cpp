/*
 * @file   5.从尾到头打印链表.cpp
 * @date   2019.3.5.
 * @author GBW
 * @Description: 输入一个链表的头结点，从尾到头反过来打印每个结点的值
 
 * @Note:
	1.确认是否可以改变链表的结构
	2.从后往前，典型的"后进先出"，可以用栈来实现
	3.递归
	4.链表就地逆序
 */
#include<iostream>
#include<stack>
using namespace std;
typedef struct Node
{
	int data;
	struct Node* next;

}Node;



// 头插法
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

// 尾插法
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


// 释放链表空间
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

// 不可改变链表结构: 借助栈完成
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

// 不可改变链表结构: 递归打印
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



// 可改变链表结构: 就地链表逆序
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
