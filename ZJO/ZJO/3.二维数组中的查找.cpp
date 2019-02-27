/*
 * @file   3.二维数组中的查找.cpp
 * @date   2019.2.27.
 * @author GBW
 * @Description: 在一个二维数组中，每一行都是从左到右递增排序，每一列都是从上到下递增排序。
				 输入这样的一个二维数组和一个整数，判读该数组是否含有该整数。
 
 * @Note:
	1.首先选取数组中右上角(左下角)的数字，如果该数字等于要查找的数字，查找过程结束。
	2.如果该数字大于要查找的数据，则剔除该数字所在的列。
	3.如果该数字小于要查找的数字，则剔除该数字所在的行。
 
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