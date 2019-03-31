/*
 * @file   let02_使用队列实现栈.cpp
 * @date   2019.3.26.
 * @author GBW
 * @Description: 设计一个栈，支持基本的栈操作，这个栈的内部存储数据的结构为队列，队列的方法只能包括push、peek(front)、pop、size、empty等标准的队列方法
 
 * @Note:

 
 */
class  MyStack
{
public:
	MyStack() {}

	void push()
	{
		queue<int> temp_queue;
		temp_queue.push(x);
		while(!data.empty())
		{ 
			temp_queue.push(data.front());
			data.pop();
		}
		while (!temp_queue.empty())
		{
			data.push(temp_queue.front());
			temp_queue.pop();
		}
	}
	
	int pop()
	{
		int c = data.front(); // 取栈顶元素，即为队列头部元素
		data->pop();           // 弹出队列头部元素 
		return x;              // 返回取出的队列头部元素x,即为栈顶元素
	}
	int top()
	{
		return data.front(); // 返回栈顶即直接返回队列头部元素
	}
	bool empty()
	{
		return data.empty();
	}
private:
	queue<int> data;

};


