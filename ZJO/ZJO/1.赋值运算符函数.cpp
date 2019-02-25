/*
 * @file   1.��ֵ���������.cpp
 * @date   2019.2.21.'
 * @author GBW
 * @Description: ����Ϊ����CMyString����������Ϊ��������Ӹ�ֵ�����������
 
 * @Note:
	1.C++������һ������һ�������������⺯�����ͻ�Ϊ�ú������麯�������ڸ����͵�ÿ��ʵ�������һ��ָ���麯�����ָ�룻
	  ��32bit�����ϣ�һ��ָ��ռ4���ֽ�
	  ��64bit�����ϣ�һ��ָ��ռ8���ֽ�
	2.sizeof(����) // ==1
	  �����͵�ʵ���в������κ���Ϣ������Ӧ����sizeofӦ����0�����ǵ��������������͵�ʵ����ʱ�����������ڴ���ռ��һ���Ŀռ䣬�����޷�ʹ��
	  ��Щʵ��������ռ�����ڴ棬�ɱ�����������visual stdio ��ÿ�������͵�ʵ��ռ��1�ֽڵĿռ䡣

	3.<��д����Ӧ��ע>
		1.�Ƿ�ѷ���ֵ����������Ϊ�����͵����ã����ں�������ǰ����ʵ�����������(*this),ֻ�з���һ�����ã��ſ�������������ֵ��
		2.�Ƿ�Ѵ���Ĳ�������������Ϊ�������ã��������Ĳ����������ö���ʵ������ô���βε�ʵ�λ����һ�θ��ƹ��캯��
		3.�Ƿ��ͷ�ʵ���������е��ڴ�,��������ڷ������ڴ�֮ǰ�ͷ��������еĿռ䣬���򽫳����ڴ�й©��
		4.�Ƿ��жϴ���Ĳ����͵�ǰ��ʵ��(*this)�ǲ���ͬһ��ʵ��

	  
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
		��version_1�У���delete�ͷ���ʵ��m_pData���ڴ�.�����ʱ�ڴ治�㵼��new char�׳��쳣��m_pData����һ����ָ�롣
		һ����ֵ����������ڲ��׳�һ���쳣��CMyString��ʵ�����ٱ�����Ч״̬��Υ�����쳣��ȫ��ԭ��
	 */
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

// version_2
solution:
	1.����new ���������ݣ�����delete�ͷ����е����ݡ�
	2.�ȴ���һ����ʱʵ�����ٽ�����ʱʵ����ԭ����ʵ����
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