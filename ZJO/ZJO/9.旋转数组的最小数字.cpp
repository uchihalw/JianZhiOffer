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
int Min(int * numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new exception("Invalid param");
	int left = 0;
	int right = length - 1;
	int resMid = left;
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