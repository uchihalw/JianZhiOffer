/*
 * @file   8.��������.cpp
 * @date   2019.3.12.
 * @author GBW
 * @Description: 
 
 * @Note:
	1.�ؼ���������������ѡ��һ������
	2.�������е����ַ�Ϊ������
	  ��ѡ�������С���Ƶ��������ߣ���ѡ������ִ�������Ƶ�������ұ�
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

// �Թ�˾����Ա������������
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