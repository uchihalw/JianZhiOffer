/*
 * @file   let02_ʹ��ջʵ�ֶ���.cpp
 * @date   2019.3.26.
 * @author GBW
 * @Description: ���һ�����У�֧�ֻ����Ķ��в�����������е��ڲ��洢���ݵĽṹΪջ��
 
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
		int c = data.top(); // ȡջ��Ԫ�أ���Ϊ����ͷ��Ԫ��
		data.pop();           // ��������ͷ��Ԫ�� 
		return x;              // ����ȡ���Ķ���ͷ��Ԫ��x,��Ϊջ��Ԫ��
	}
	int peek()
	{
		return data.top(); // ����ջ����ֱ�ӷ��ض���ͷ��Ԫ��
	}
	bool empty()
	{
		return data.empty();
	}


private:
	stack<int> stk;
};