/*
* @file   9.��ת�������С����.cpp
* @date   2019.3.15.
* @author GBW
* @Description: ��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ����Ϊ�������ת
����һ��(���������)�����һ����ת�������ת�������СԪ��(��СԪ�ظպ���������������ķֽ���)

* @Note:
1.��ͷ��β��������һ�Σ������ҳ���СԪ��O(n)
2.��ת֮�������ʵ���Ͽ��Ի���Ϊ��������������飬����ǰ����������Ԫ�ض�
���ڻ��ߵ��ں����������Ԫ��
3.��СԪ�ظպ���������������ķֽ���
4.���ö��ַ�O(logn)
5.��������ָ�룬��һ������ָ��ǰ����������Ԫ�أ��ڶ�������ָ�������������Ԫ��
���գ���һ��ָ�뽫ָ��ǰ������������һ��Ԫ�أ����ڶ���ָ���ָ�����������ĵ�
һ��Ԫ�ء�Ҳ�����������ջ�ָ���������ڵ�Ԫ�أ����ڶ���ָ��ָ��ĸպ�����С��Ԫ��
�����ѭ������������.

*/
// version_1 [3,4,5,1,2]
int Min(int * numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new exception("Invalid param");
	int left = 0;
	int right = length - 1;
	int resMid = left; // ��������������ǰ���0��Ԫ�ذᵽ���棬���������鱾���䣬����Ȼ�������һ����ת���ʽ�redMid��ʼ��Ϊleft
	while (numbers[left] >= numbers[right])
	{
		if (right - left == 1)
		{
			resMid = right;
			break;
		}
		resMid = (left + right) / 2;
		if (numbers[resMid] >= numbers[left])
			left = resMid;
		else if (numbers[resMid] <= numbers[right])
			right = resMid;

	}
	return numbers[resMid];
}
// version_2 [1,1,1,0,1] 
// ��left == rightʱ���޷��ж�mid=1�Ǵ��ڵ�һ�����������黹�ǵڶ������������飬Ҳ���޷��ƶ�����ָ������С���ҵķ�Χ����ʱ��Ҫ����˳����ҵİ취
int Min(int* numbers, int length)
{
	if (numbers = NULL || length <= 0)
		throw new exception("Invalid parameters");

	int left = 0;
	int right = length - 1;
	int resMid = left;

	while (numbers[left] >= numbers[right]) //  ��λ����������������ı߽�
	{
		if (right - left == 1)
		{
			resMid = right;
			break;
		}
		resMid = (left + right) / 2;


		if (numbers[resMid] == numbers[left] && numbers[resMid] == numbers[right])
		{
			return MinInOrder(numbers, left, right);
		}
		if (numbers[resMid] >= numbers[left])
			left = resMid;
		else if (numbers[resMid] <= numbers[right])
			right = resMid;

		
	}
}
int MinInOrder(int* numbers, int left, int right)
{
	int result = numbers[left];
	for (int i=left+1;i<right;i++)
	{
		if (result > numbers[i])
			result = numbers[i];
	}
	
	return result;
}