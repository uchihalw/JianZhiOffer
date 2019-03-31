/*
 * @file   let02_ʹ�ö���ʵ��ջ.cpp
 * @date   2019.3.26.
 * @author GBW
 * @Description: ���һ��ջ��֧�ֻ�����ջ���������ջ���ڲ��洢���ݵĽṹΪ���У����еķ���ֻ�ܰ���push��peek(front)��pop��size��empty�ȱ�׼�Ķ��з���
 
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
		int c = data.front(); // ȡջ��Ԫ�أ���Ϊ����ͷ��Ԫ��
		data->pop();           // ��������ͷ��Ԫ�� 
		return x;              // ����ȡ���Ķ���ͷ��Ԫ��x,��Ϊջ��Ԫ��
	}
	int top()
	{
		return data.front(); // ����ջ����ֱ�ӷ��ض���ͷ��Ԫ��
	}
	bool empty()
	{
		return data.empty();
	}
private:
	queue<int> data;

};


