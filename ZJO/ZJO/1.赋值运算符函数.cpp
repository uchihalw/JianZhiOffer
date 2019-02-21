/*
 * @file   1.赋值运算符函数.cpp
 * @date   2019.2.21.'
 * @author GBW
 * @Description: 如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
 
 * @Note:
	1.C++编译器一旦发现一个类型中有虚拟函数，就会为该函数生虚函数表，并在该类型的每个实例中添加一个指向虚函数表的指针；
	  在32bit机器上，一个指针占4个字节
	  在64bit机器上，一个指针占8个字节
	  sizeof(空类) // ==1
 */
#include <iostream>
using namespace std;

class sizeTest
{
public:
	sizeTest() {}

	~sizeTest() {}

	virtual void testFunc() {}

	virtual void testFunc1() = 0;
};


class CMyString
{
public:
	CMyString(char *pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);
private:
	char *m_pData;
};

void main()
{
	cout << sizeof(sizeTest) << endl;

}