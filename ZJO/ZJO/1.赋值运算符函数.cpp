/*
 * @file   1.赋值运算符函数.cpp
 * @date   2019.2.21.'
 * @author GBW
 * @Description: 如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
 
 * @Note:
	1.C++编译器一旦发现一个类型中有虚拟函数，就会为该函数生虚函数表，并在该类型的每个实例中添加一个指向虚函数表的指针；
	  在32bit机器上，一个指针占4个字节
	  在64bit机器上，一个指针占8个字节
	2.sizeof(空类) // ==1
	  空类型的实例中不包含任何信息，本来应该求sizeof应该是0，但是当我们声明该类型的实例的时候，它必须在内存中占有一定的空间，否则无法使用
	  这些实例，至于占多少内存，由编译器决定，visual stdio 中每个空类型的实例占用1字节的空间。

	3.<编写代码应关注>
		1.是否把返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用(*this),只有返回一个引用，才可以允许连续赋值。
		2.是否把传入的参数的类型声明为常量引用，如果传入的参数不是引用而是实例，那么从形参到实参会调用一次复制构造函数
		3.是否释放实例自身已有的内存,如果忘记在分配新内存之前释放自身已有的空间，程序将出现内存泄漏。
		4.是否判断传入的参数和当前的实例(*this)是不是同一个实例

	  
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
	CMyString(const CMyString& str); //
	~CMyString(void);
	CMyString& operator=(const CMyString& str);
private:
	char *m_pData;
};


//version_1
CMyString& CMyString::operator=(const CMyString &str)
{
	if (this == &str)
	{
		return *this;
	}
	delete[] m_pData; 
	m_pData = NULL;
	/**
		在version_1中，在delete释放了实例m_pData的内存.如果此时内存不足导致new char抛出异常，m_pData将是一个空指针。
		一旦赋值运算符函数内部抛出一个异常，CMyString的实例不再保持有效状态，违背了异常安全性原则。
	 */
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

// version_2
solution:
	1.先用new 分配新内容，再用delete释放已有的内容。
	2.先创建一个临时实例，再交换临时实例和原来的实例。
CMyString& CMyString::operator =(const CMyString& str)
{
	if (this != &str)
	{
		CMyString strTemp(str);

		char *pTmep = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTmep;
	}
	return *this;
}

void main()
{
	cout << sizeof(sizeTest) << endl;

}