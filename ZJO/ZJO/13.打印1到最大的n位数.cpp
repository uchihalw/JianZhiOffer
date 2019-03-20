/*
 * @file   13.��ӡ1������nλ��.cpp
 * @date   2019.3.19.
 * @author GBW
 * @Description: ��������n,��˳���ӡ����1������nλʮ����������������3�����ӡ��1��2��3һֱ������3λ����999  
 
 * @Note:
 
 */

0. version_0
// ��n�����ʱ�򣬻�������
void Print1ToMaxOfNDigits(int n)
{
	int number = 1;
	int i = 0;
	while (i++<n)
	{
		number *= 10;
	}
	for (i = 1; i < number; ++i)
		printf("%d\t",i);
}


1. version_1
// �����������Ҫ���һ�����������õķ��������ַ������������������
// �˴����ַ����������������
// ���ַ�����ʾ���ֵ�ʱ����ֱ�۵ķ��������ַ�����ÿ���ַ�����0-9֮���ĳ���ַ���������ʾ�����е�һλ
// ��Ϊ���������n������Ҫһ������Ϊn+1���ַ���
/*
	���Ȱ��ַ����е�ÿһ�����ֶ���ʼ��Ϊ'0'��Ȼ��ÿһ��Ϊ�ַ�����ʾ�����ּ�1���ٴ�ӡ������
	1.���ַ�������������ģ��ӷ�
	2.���ַ����������ִ�ӡ����
*/
void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}
	delete[] number;
}

// �ڱ�ʾ���ֵ��ַ���number������1
bool Increment(char *number)
{
	bool isOverFlow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i = nLength - 1)
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0) // 999...99 �� 1��ʱ�򣬻��ڵ�һ���ַ�(�±�Ϊ0)�Ļ����ϲ�����λ������������������ٵ�һ���ַ��ϲ�����λ��
						// �ʵ������ڼ�1ʱ��һ���ַ������˽�λ�����Ѿ�������nλ��
				isOverFlow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1; // ��λ��־
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverFlow;

}
// 098 -> 98
void PrintNumber(char* number)
{
	bool isBeginning = true;
	int nLength = strlen(number);

	for (int i = 0; i<nLength;++i)
	{
		if (isBeginning && number[i] != '0')
			isBeginning = false;
		if (!isBeginning)
			printf("%c", number[i]);
		
	}
}

2. version_2
// ȫ����
void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecur(number, n, 0);
	}
	delete[] number;
}

void Print1ToMaxOfNDigitsRecur(char *number, int length, int index)
{
	if (index == length-1)
	{
		PrintNumber(number);
		return;
	}
	for (int i =0; i<10;i++)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecur(number, length, index + 1);
	}
}