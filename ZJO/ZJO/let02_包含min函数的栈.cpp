/*
 * @file   let02_����min������ջ.cpp
 * @date   2019.3.26.
 * @author GBW
 * @Description: ���һ��ջ��֧�����²���������Щ�����ĸ��Ӷ��ǳ���������O(1).getMin()����վ����СԪ��
 
 * @Note:
 ջ��ÿһ��״̬������Ҫ��һ��������¼��Сֵ������Сֵջ
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
	stack<int> data; // ����ջ
	stack<int> mins; // ��Сֵջ
};

