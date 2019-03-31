/*
 * @file   30.数组中出现次数超过一般的数字.cpp
 * @date   2019.3.27.
 * @author GBW
 * @Description: 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 
 * @Note:
 
 */
// version_1
/*
	数组中有一个数字的出现次数超过了数组长度的一半，如果把这个数组排序，那么排序之后位于数组中间的数字一定就是那个出现
	次数超过数组长度一半的数字，也就是中位数。即长度为n的数组中第n/2大的数字。
*/
class Solution {
public:
	bool CheckInvalidArray(vector<int> number)
	{
		if (number.size() == 0)
			return false;
		return true;
	}

	bool checkMoreThanHalf(vector<int> number, int length, int res)
	{
		int times = 0;
		for (int i = 0; i < length; i++)
		{
			if (number[i] == res)
				times++;
		}

		if (times * 2 <= length)
			return false;
		return true;


	}
	void Qsort(vector<int> &number, int left, int right)//快排
	{

		int key = number[left];
		int i = left;
		int j = right;

		if (left < right)
		{
			while (i < j)
			{
				while (i < j && number[j] >= key)
				{
					j--;
				}
				number[i] = number[j];
				while (i < j && number[i] <= key)
				{
					i++;
				}
				number[j] = number[i];
			}
			number[j] = key;
			Qsort(number, left, j - 1);
			Qsort(number, j + 1, right);
		}

	}
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (CheckInvalidArray(numbers) == false)
			return 0;
		int length = numbers.size();
		int middle = length >> 1;
		int result = numbers[middle];
		int left = 0;
		int right = length - 1;
		Qsort(numbers, left, right);
		if (checkMoreThanHalf(numbers, length, result) == false)
			return 0;
		return result;
	}
};

//version_2
/*
	遍历数组的时候保存两个值:一个是数组中的一个数字；一个是次数
	1. 当我们遍历到下一个数字的时候，如果下一个数字和我们之前保存的数字相同，则次数加1
	2. 如果下一个数字和我们之前保存的数字不同，则减1
	3. 如果次数为0，我们需要保存下一个数字，并把次数设为1
*/
bool checkMoreThanHalf(vector<int> number, int length, int res)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (number[i] == res)
			times++;
	}

	if (times * 2 <= length)
		return false;
	return true;


}
int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.size() == 0)
		return 0;
	int findNum = 0; // 出现次数超过一半的次数
	int cnt = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (cnt == 0) // cnt = 0,表示当前的findNum需要重选
		{
			findNum = numbers[i];
			cnt = 1;
		}
		else
		{
			if (findNum == numbers[i])
				cnt++;
			else
				cnt--;
		}
	}

	if (!checkMoreThanHalf(numbers, numbers.size(), findNum));
		return 0;
	return findNum;
}