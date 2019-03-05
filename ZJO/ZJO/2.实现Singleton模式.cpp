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
	2.����ģʽ�Ƿ��̰߳�ȫ��
 */

/*
* @version_1

* @solution:

* @fault:
�ڶ��̵߳�����£��Ϳ��ܴ������Singletonʵ��
*/
class Singleton
{
public:
	static Singleton *Instance()
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
private:
	Singleton() { }
	static Singleton* m_Instance;
};
Singleton* Singleton::m_Instance = NULL;

/*
* @version_2

* @solution:
1.ʹ����ν��"˫����"���ƣ���Ϊ����һ�μ����ͽ�������Ҫ������Ӧ����

* @fault:
������д����ݲ�����������������Ϊһ�����ܵ�ƿ����ÿ�η��ʺ�������Ҫ����һ�μ���������������ʵ����ֻ��
m_Instance��ʼ��ʱ��Ҫ������Ҳ����˵��������ֻ��Instance()��һ�α����ò��Ǳ�Ҫ�ġ�
������������У�Instance()��������n�Σ���ôֻ�е�һ�ε������������á�
*/
class Singleton
{
public:
	static Singleton *Instance()
	{
		
		Lock();
		if (m_Instance == NULL)
			m_Instance = new Singleton();
		unLock();
		

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
private:
	Singleton() { }
	static Singleton* m_Instance;
};
Singleton* Singleton::m_Instance = NULL;

/*
* @version_3

* @solution:
1.ʹ����ν��"˫����"���ƣ���Ϊ����һ�μ����ͽ�������Ҫ������Ӧ���ۣ������������жϣ��Ϳ��Ա����μ�����
����������ͬʱҲ��֤���̰߳�ȫ��
2.DCLP���������ڵ���Instance()ʱ��m_Instance�ڴ󲿷�ʱ���Ƿǿյģ����û��Ҫ�ٴγ�ʼ����
���ԣ�DCLP�ڼ���֮ǰ������һ��m_Instance�Ƿ�Ϊ�ռ�顣ֻ���жϽ��Ϊ�棬���������Ż���С�
Ȼ���ٴμ��m_Instance�Ƿ�Ϊ�ա��ڶ��μ���Ǳز����ٵġ��ڵ�һ�μ���m_Instance�ͼ���֮ǰ������������
һ���̶߳�m_Instance���г�ʼ����

* @fault:
������д����ݲ�����������������Ϊһ�����ܵ�ƿ����
*/
class Singleton
{
public:
	static Singleton *Instance()
	{
		if (m_Instance == NULL)
		{
			// C++ û��ֱ�ӵ�Lock()����,�˴���������NULL�ж�
			Lock(); 
			if (m_Instance == NULL)
				m_Instance = new Singleton();
			unLock();
		}
				
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
private:
	Singleton() { }
	static Singleton* m_Instance;
};
Singleton* Singleton::m_Instance = NULL;

/*
* @version_4

* @solution:
��̬��ʼ���ڳ���ʼʱ��Ҳ���ǽ��뺯��֮ǰ�������߳��Ե��̷߳�ʽ��ɳ�ʼ����
���Ծ�̬��ʼ����֤���̰߳�ȫ�ԡ�������Ҫ��Ƚϸ�ʱ����ͨ���˷�ʽ����Ƶ���ļ���
�ͽ�����ɵ���Դ�˷ѡ�

* @fault:
δ���ǵ�ʵ�������١�
*/
class Singleton
{
public:
	static Singleton *Instance()
	{
		return const_cast<Singleton*>(m_Instance);
	}
	static void DestroyInstance()
	{
		if (m_Instance != NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}

private:
	Singleton() { }
	static Singleton* m_Instance;
};
Singleton* Singleton::m_Instance = NULL;

/*
* @version_5

* @solution:
ʵ��������
* @fault:

*/
class Singleton
{
public:
	static Singleton *Instance()
	{
		static Singleton m_Instance;
		return &m_Instance;
	}
	static void DestroyInstance()
	{
		if (m_Instance != NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}
private:
	Singleton() { }
};




// valatile
pInstance = new Singleton();
	1.ΪSingleton�������һƬ�ڴ�
	2.����һ��Singleton���󣬴����ѷ�����ڴ���
	3.��pInstanceָ����Ƭ�ڴ档
//**������������ǿ�ư�������˳��ִ�У�ʵ���ϱ�������ʱ�ύ��2��3��ִ��˳��