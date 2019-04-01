/*
 * @file   21.˳ʱ���ӡ����.cpp
 * @date   2019.4.1.
 * @author GBW
 * @Description: ����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿ������
 
 * @Note:
 
 */
/*
	1. ��һ��������Ҫ�ģ���Ϊ��ӡһȦ������һ��
	2. ���ֻ��һ�У���ô�Ͳ���Ҫ�ڶ����ˣ�Ҳ������Ҫ�ڶ�����ǰ����������ֹ�кŴ�����ʼ�к�
	3. ��Ҫ��������������Ȧ���������������У�Ҳ����˵����Ҫ����ֹ�кŴ�����ʼ�к�֮�⣬��Ҫ����ֹ�кŴ�����ʼ�к�
	4. ��Ҫ��ӡ���Ĳ����������������������У����Ҫ����ֹ�кű���ʼ�к����ٴ���2��ͬʱ��ֹ�кŴ�����ʼ�к�
*/

void PrintMatrix(int **number, int columns, int rows)
{
	if (number == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while (columns > start *2 && rows>start*2)
	{
		// �̶������X.Y
		int endX = columns - 1 - start;
		int endY = rows - 1 - start;

		// �������Ҵ�ӡһ��
		for (int i=start;i<=endX;i++)
		{
			cout << number[start][i];
		}

		// ���ϵ��´�ӡһ��
		if (start < endY)
		{
			for (int i = start + 1; i <= endY; i++)
			{
				cout << number[i][endX];
			}
		}

		// ���ҵ����ӡһ��
		if (start < endX && start<endY)
		{
			for (int i = endX-1; i >= start; i--)
			{
				cout << number[endY][i];
			}
		}

		// ���µ��ϴ�ӡһ��
		if (start<endX && start<endY-1)
		{
			for (int i = endY - 1; i >= start + 1; i--)
			{
				cout << number[i][start];
			}
		}
		

	}
}