/*
 * @file   2.ʵ��Singletonģʽ.cpp
 * @date   2019.2.25.
 * @author GBW
 * @Description: ���һ���࣬����ֻ�����ɸ����һ��ʵ����
 
 * @Note:
	1.Singleton:��֤һ����ֻ��һ��ʵ�������ṩһ����������ȫ�ַ��ʵ㡣
		1.���ȣ������У�Ҫ����һ��ʵ�����ͱ��������Ĺ��캯������ˣ�Ϊ��ֹ���ⲿ������Ĺ��캯��������ʵ������Ҫ�����캯������Ϊprivate.
		  ��Ϊ��procted(ȡ��protecd����������ʹ���������඼�ᱻ�ƻ�)��public��Աһ��ȱ����װ�ԡ�
		2.��Ҫ�ṩ��ȫ�ַ��ʵ㣬��Ҫ�����ж���һ��static���������������ڲ�Ψһ�����ʵ����
 */
class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (m_Instance == NULL)
			m_Instance = new Singleton();
		return m_Instance;
	}

	static void DestroyInstance()
	{
		if (m_Instance != NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}

	int GetTest()
	{
		return m_test��
	}

private:
	Singleton() {
		m_test = 10;
	}
	static Singleton* m_Instance;
	int m_test;
};
Singleton* Singleton::m_Instance = NULL;
int main()
{
	Singleton *singleObj = Singleton::GetInstance();
	singleObj->GetTest();
	Singleton::DestroyInstance();
}