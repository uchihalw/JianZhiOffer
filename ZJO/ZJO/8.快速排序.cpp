/*
 * @file   8.快速排序.cpp
 * @date   2019.3.12.
 * @author GBW
 * @Description: 
 
 * @Note:
	1.关键在于先在数字中选择一个数字
	2.把数组中的数字分为两部分
	  比选择的数字小的移到数组的左边，比选择的数字大的数字移到数组的右边
 */
int Partition(int data[], int length, int start, int end)
{
	if (data == NULL || length < 0 || start < 0 || end >= length)
		throw new std::exception("Invalid Parameters");
	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				Swap(&data[index], &data[small);
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}
void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	if (index < start)
		QuickSort(data, length, index + 1, end);
}

// 对公司所有员工的年龄排序
void sortAges(int ages[], int length)
{
	if (ages == nullptr || length <= 0)
		return;

	const int oldOfAge = 99;
	int timeOfAge[oldOfAge + 1];
	for (int i = 0; i <= oldOfAge; ++i)
		timeOfAge[i] = 0;

	for (int i = 0; i < length; ++i)
	{
		int age = ages[i];
		if (age<0 || age > oldOfAge)
			throw new exception("age out of range");
		++timeOfAge[age];
	}
	int index = 0;
	for (int i = 0; i <= oldOfAge; ++i)
	{
		for (int j = 0; j < timeOfAge[i]; ++j)
		{
			ages[index] = i;
			++index;
		}
	}

}