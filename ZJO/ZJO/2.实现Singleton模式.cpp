/*
 * @file   2.实现Singleton模式.cpp
 * @date   2019.2.25.
 * @author GBW
 * @Description: 设计一个类，我们只能生成该类的一个实例。
 
 * @Note:
	1.Singleton:保证一个类只有一个实例，并提供一个访问它的全局访问点。
		1.首先，在类中，要构造一个实例，就必须调用类的构造函数。因此，为防止在外部调用类的构造函数而构造实例，需要将构造函数声明为private.
		  因为，procted(取消protecd变量，所有使用它的子类都会被破坏)和public成员一样缺乏封装性。
		2.需要提供给全局访问点，需要在类中定义一个static函数，返回在类内部唯一构造的实例。
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
		return m_test；
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