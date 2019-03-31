/*
 * @file   let02_使用栈实现队列.cpp
 * @date   2019.3.26.
 * @author GBW
 * @Description: 设计一个队列，支持基本的队列操作，这个队列的内部存储数据的结构为栈。
 
 * @Note:
 
 */
class MyQueue
{
public:
	void push(int x)
	{
		stack<int> tmp_stk;
		while (!data->empty())
		{
			tmp_stk.push(data.top());
			data.pop();
		}
		tmp_stk.push(x);
		while (!tmp_stk.empty())
		{
			data.push(tmp_stk.top());
			tmp_stk.pop();
		}
	}

	int pop()
	{
		int c = data.top(); // 取栈顶元素，即为队列头部元素
		data.pop();           // 弹出队列头部元素 
		return x;              // 返回取出的队列头部元素x,即为栈顶元素
	}
	int peek()
	{
		return data.top(); // 返回栈顶即直接返回队列头部元素
	}
	bool empty()
	{
		return data.empty();
	}


private:
	stack<int> stk;
};