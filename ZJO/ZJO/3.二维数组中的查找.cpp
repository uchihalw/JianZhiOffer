/*
 * @file   3.��ά�����еĲ���.cpp
 * @date   2019.2.27.
 * @author GBW
 * @Description: ��һ����ά�����У�ÿһ�ж��Ǵ����ҵ�������ÿһ�ж��Ǵ��ϵ��µ�������
				 ����������һ����ά�����һ���������ж��������Ƿ��и�������
 
 * @Note:
	1.����ѡȡ���������Ͻ�(���½�)�����֣���������ֵ���Ҫ���ҵ����֣����ҹ��̽�����
	2.��������ִ���Ҫ���ҵ����ݣ����޳����������ڵ��С�
	3.���������С��Ҫ���ҵ����֣����޳����������ڵ��С�
 
 */
bool Find(int *matrix, int rows, int columns, int number)
{
	bool found = false;
	if (matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (matrix[row * columns + column] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number)
				--column;
			else
				++row;
		}
		return found;
	}
}