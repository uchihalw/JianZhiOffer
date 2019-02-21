/*
 * @file   1.��ֵ���������.cpp
 * @date   2019.2.21.'
 * @author GBW
 * @Description: ����Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������
 
 * @Note:
	1.C++������һ������һ�������������⺯�����ͻ�Ϊ�ú������麯�������ڸ����͵�ÿ��ʵ�������һ��ָ���麯�����ָ�룻
	  ��32bit�����ϣ�һ��ָ��ռ4���ֽ�
	  ��64bit�����ϣ�һ��ָ��ռ8���ֽ�
	  sizeof(����) // ==1
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