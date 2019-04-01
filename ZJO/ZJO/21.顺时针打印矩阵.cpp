/*
 * @file   21.顺时针打印矩阵.cpp
 * @date   2019.4.1.
 * @author GBW
 * @Description: 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每个数字
 
 * @Note:
 
 */
/*
	1. 第一步总是需要的，因为打印一圈至少有一步
	2. 如果只有一行，那么就不需要第二步了，也就是需要第二步的前提条件是终止行号大于起始行号
	3. 需要第三步的条件是圈内至少有两行两列，也就是说除了要求终止行号大于起始行号之外，还要求终止列号大于起始列号
	4. 需要打印第四步的条件是至少有三行两列，因此要求终止行号比起始行号至少大于2，同时终止列号大于起始列号
*/

void PrintMatrix(int **number, int columns, int rows)
{
	if (number == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while (columns > start *2 && rows>start*2)
	{
		// 固定矩阵的X.Y
		int endX = columns - 1 - start;
		int endY = rows - 1 - start;

		// 从左至右打印一行
		for (int i=start;i<=endX;i++)
		{
			cout << number[start][i];
		}

		// 从上到下打印一行
		if (start < endY)
		{
			for (int i = start + 1; i <= endY; i++)
			{
				cout << number[i][endX];
			}
		}

		// 从右到左打印一行
		if (start < endX && start<endY)
		{
			for (int i = endX-1; i >= start; i--)
			{
				cout << number[endY][i];
			}
		}

		// 从下到上打印一行
		if (start<endX && start<endY-1)
		{
			for (int i = endY - 1; i >= start + 1; i--)
			{
				cout << number[i][start];
			}
		}
		

	}
}