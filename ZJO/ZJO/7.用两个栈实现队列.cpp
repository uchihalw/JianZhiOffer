/*
 * @file   7.������ջʵ�ֶ���.cpp
 * @date   2019.3.8.
 * @author GBW
 * @Description: ������ջʵ��һ�����У����е��������¡�ʵ��������������appendTail��deleteHead��
				 �ֱ�����ڶ���β��������Ͷ���ͷ��ɾ�����Ĺ���
 
 * @Note:
	 1. queue_1 =  stack_1 + stack_2
	 2. stack_1: �����Ƿ�Ϊ�գ�ֻ����Ԫ��ѹ��(����β��������)
	 3. stack_2: (����ͷ��ɾ�����)
				 1.Ϊ��ʱ����stack_1�е�Ԫ���������£�����ѹ��stack_2
				 2.��Ϊ��ʱ��ֱ�Ӵ�stack_2ִ��ɾ������
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