/*
 * @file   7.用两个栈实现队列.cpp
 * @date   2019.3.8.
 * @author GBW
 * @Description: 用两个栈实现一个队列，队列的声明如下。实现它的两个函数appendTail和deleteHead，
				 分别完成在队列尾部插入结点和队列头部删除结点的功能
 
 * @Note:
	 1. queue_1 =  stack_1 + stack_2
	 2. stack_1: 无论是否为空，只负责元素压入(队列尾部插入结点)
	 3. stack_2: (队列头部删除结点)
				 1.为空时，将stack_1中的元素由上至下，依次压入stack_2
				 2.不为空时，直接从stack_2执行删除操作
 */

#include <queue>
using namespace std;

template <typename T> class  CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& element);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};
template<typename T> void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)
	{
		throw new exception("queue is empty");
	}
	T head = stack2.top();
	stack2.pop();
	return head;
}