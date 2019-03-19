/*
 * @file   12.面值的整数次方.cpp
 * @date   2019.3.19.
 * @author GBW
 * @Description: 实现函数double Power(double base, int exponent),求base的exponent次方。不得使用库函数，同时也不需要考虑大数问题 
 
 * @Note:
 
 */
0. version_0
// 没有考虑异常以及边界值问题
double Power(double base, int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; ++i)
		result *= base;
	return result;
}

1. version_1
bool g_InvalidInput = false;
double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent); // 获得指数的次方的绝对值
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}



// 判断两个小数是否相等，只能判断它们之差的绝对值是不是在一个很小的范围内。如果两个数相差很小，就可以认为它们相等
bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

double PowerWithUnsignedExponent_1(double base, unsigned int exponent)
{
	double result = 1.0;
	for (int i = 1; i <= exponent; i++)
		result *= base;
	return result;
}


double PowerWithUnsignedExponent_2(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double result = PowerWithUnsignedExponent_2(base, exponent >> 1); // 用右移运算符代替除2
	result *= result;
	if (exponent & 0x1 == 1) // exponent为奇数 ,用位与运算符代替了求余运算(%)判断一个数是奇数还是偶数
		result *= base;
	return result;
}