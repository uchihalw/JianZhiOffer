/*
 * @file   30.�����г��ִ�������һ�������.cpp
 * @date   2019.3.27.
 * @author GBW
 * @Description: ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
 
 * @Note:
 
 */
// version_1
/*
	��������һ�����ֵĳ��ִ������������鳤�ȵ�һ�룬������������������ô����֮��λ�������м������һ�������Ǹ�����
	�����������鳤��һ������֣�Ҳ������λ����������Ϊn�������е�n/2������֡�
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
	void Qsort(vector<int> &number, int left, int right)//����
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
	���������ʱ�򱣴�����ֵ:һ���������е�һ�����֣�һ���Ǵ���
	1. �����Ǳ�������һ�����ֵ�ʱ�������һ�����ֺ�����֮ǰ�����������ͬ���������1
	2. �����һ�����ֺ�����֮ǰ��������ֲ�ͬ�����1
	3. �������Ϊ0��������Ҫ������һ�����֣����Ѵ�����Ϊ1
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
	int findNum = 0; // ���ִ�������һ��Ĵ���
	int cnt = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (cnt == 0) // cnt = 0,��ʾ��ǰ��findNum��Ҫ��ѡ
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