/*
 * @file   12.��ֵ�������η�.cpp
 * @date   2019.3.19.
 * @author GBW
 * @Description: ʵ�ֺ���double Power(double base, int exponent),��base��exponent�η�������ʹ�ÿ⺯����ͬʱҲ����Ҫ���Ǵ������� 
 
 * @Note:
 
 */
0. version_0
// û�п����쳣�Լ��߽�ֵ����
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

	unsigned int absExponent = (unsigned int)(exponent); // ���ָ���Ĵη��ľ���ֵ
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);
	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}



// �ж�����С���Ƿ���ȣ�ֻ���ж�����֮��ľ���ֵ�ǲ�����һ����С�ķ�Χ�ڡ��������������С���Ϳ�����Ϊ�������
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
	double result = PowerWithUnsignedExponent_2(base, exponent >> 1); // ����������������2
	result *= result;
	if (exponent & 0x1 == 1) // exponentΪ���� ,��λ���������������������(%)�ж�һ��������������ż��
		result *= base;
	return result;
}