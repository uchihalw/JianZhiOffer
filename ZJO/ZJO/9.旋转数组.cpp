/*
* @file   9.旋转数组的最小数子.cpp
* @date   2019.3.15.
* @author GBW
* @Description: 把一个数组最开始的若干个元素搬到数组的末尾，称为数组的旋转
输入一个(递增排序的)数组的一个旋转，输出旋转数组的最小元素(最小元素刚好是这两个子数组的分界线)

* @Note:
1.从头到尾遍历数组一次，就能找出最小元素O(n)
2.旋转之后的数组实际上可以划分为两个排序的子数组，而且前面的子数组的元素都
大于或者等于后面子数组的元素
3.最小元素刚好是这两个子数组的分界线
4.利用二分法O(logn)
5.利用两个指针，第一个总是指向前面递增数组的元素，第二个总是指向后面递增数组的元素
最终，第一个指针将指向前面子数组的最后一个元素，而第二个指针会指向后面子数组的第
一个元素。也就是它们最终会指向两个相邻的元素，而第二个指针指向的刚好是最小的元素
这就是循环结束的条件.

*/
// version_1 [3,4,5,1,2]
int Min(int * numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new exception("Invalid param");
	int left = 0;
	int right = length - 1;
	int resMid = left; // 如果把排序数组的前面的0个元素搬到后面，即有序数组本身不变，这仍然是数组的一个旋转。故将redMid初始化为left
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
// 当left == right时，无法判断mid=1是处于第一个递增子数组还是第二个递增子数组，也就无法移动两个指针来缩小查找的范围。此时需要采用顺序查找的办法
int Min(int* numbers, int length)
{
	if (numbers = NULL || length <= 0)
		throw new exception("Invalid parameters");

	int left = 0;
	int right = length - 1;
	int resMid = left;

	while (numbers[left] >= numbers[right]) //  定位到两个有序子数组的边界
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