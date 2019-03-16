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