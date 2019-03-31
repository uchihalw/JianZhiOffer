/*
 * @file   let02_包含min函数的栈.cpp
 * @date   2019.3.26.
 * @author GBW
 * @Description: 设计一个栈，支持如下操作，且这些操作的复杂度是常数级，即O(1).getMin()返回站内最小元素
 
 * @Note:
 栈的每一个状态，都需要有一个变量记录最小值，即最小值栈
 */
class MinStack
{
public:
	MinStack() {}
	void push(int x)
	{
		data.push(x);
		if (mins.empty())
			mins.push(x);
		else
		{
			if (x > mins.top())
			{
				x = mins.top();
			}
			mins.push(x);
		}
			
	}


	void pop()
	{
		data.pop();
		mins.pop();
	}

	int top()
	{
		return data.top();
	}

	int getMin()
	{
		return mins.top();
	}
private:
	stack<int> data; // 数据栈
	stack<int> mins; // 最小值栈
};

