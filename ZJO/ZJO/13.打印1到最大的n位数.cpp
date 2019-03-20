/*
 * @file   13.打印1到最大的n位数.cpp
 * @date   2019.3.19.
 * @author GBW
 * @Description: 输入数字n,按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1、2、3一直到最大的3位数即999  
 
 * @Note:
 
 */

0. version_0
// 当n过大的时候，会产生溢出
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
// 解决此问题需要表达一个大数。常用的方法是用字符串或者数组表达最大数
// 此处用字符串来解决大数问题
// 用字符串表示数字的时候，最直观的方法就是字符串里每个字符都是0-9之间的某个字符，用来表示数字中的一位
// 因为数字最大是n，故需要一个长度为n+1的字符串
/*
	首先把字符串中的每一个数字都初始化为'0'，然后每一次为字符串表示的数字加1，再打印出来。
	1.在字符串表达的数字上模拟加法
	2.把字符串表达的数字打印出来
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

// 在表示数字的字符串number上增加1
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
			if (i == 0) // 999...99 加 1的时候，会在第一个字符(下标为0)的基础上产生进位，而其他情况都不会再第一个字符上产生进位，
						// 故当发现在加1时第一个字符产生了进位，则已经是最大的n位数
				isOverFlow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1; // 进位标志
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
// 全排列
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