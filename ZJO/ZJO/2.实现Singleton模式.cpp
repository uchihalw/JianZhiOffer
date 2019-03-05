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
	2.单例模式是非线程安全的
 */

/*
* @version_1

* @solution:

* @fault:
在多线程的情况下，就可能创建多个Singleton实例
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
1.使用所谓的"双检锁"机制，因为进行一次加锁和解锁是需要付出相应代价

* @fault:
如果进行大数据操作，加锁操作将成为一个性能的瓶颈。每次访问函数都需要进行一次加锁操作，但是在实际中只有
m_Instance初始化时需要加锁，也就是说加锁操作只有Instance()第一次被调用才是必要的。
如果程序运行中，Instance()被调用了n次，那么只有第一次调用锁起了作用。
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
1.使用所谓的"双检锁"机制，因为进行一次加锁和解锁是需要付出相应代价，而进行两次判断，就可以避免多次加锁和
解锁操作，同时也保证了线程安全。
2.DCLP：调用者在调用Instance()时，m_Instance在大部分时候都是非空的，因此没必要再次初始化。
所以，DCLP在加锁之前先做了一次m_Instance是否为空检查。只有判断结果为真，加锁操作才会进行。
然后再次检查m_Instance是否为空。第二次检查是必不可少的。在第一次检验m_Instance和加锁之前，可能有另外
一个线程对m_Instance进行初始化。

* @fault:
如果进行大数据操作，加锁操作将成为一个性能的瓶颈。
*/
class Singleton
{
public:
	static Singleton *Instance()
	{
		if (m_Instance == NULL)
		{
			// C++ 没有直接的Lock()操作,此处进行两次NULL判断
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
静态初始化在程序开始时，也就是进入函数之前，由主线程以单线程方式完成初始化，
所以静态初始化保证了线程安全性。在性能要求比较高时，可通过此方式避免频繁的加锁
和解锁造成的资源浪费。

* @fault:
未考虑到实例的销毁。
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
实例的销毁
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
	1.为Singleton对象分配一片内存
	2.构造一个Singleton对象，存入已分配的内存区
	3.将pInstance指向这片内存。
//**编译器并不会强制按照以上顺序执行，实际上编译器有时会交换2和3的执行顺序。