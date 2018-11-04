#include <iostream>
#include <mutex>
using namespace  std;
//饿汉式(简单、可能会导致启动变慢）
class SingletonE
{
public:
	//static SingletonE* GetSingletonE()
	//{
	//	return &_sInstance;
	//}
	static SingletonE& GetSingletonE()
	{
		return _sInstance;
	}
private:
	SingletonE(){}
	//防止拷贝C++98
	//SingletonE(const SingletonE&);//屏蔽拷贝构造
	//SingletonE& operator=(const SingletonE&);

	//C++11
	SingletonE(const SingletonE&) = delete;//屏蔽拷贝构造
	SingletonE& operator=(const SingletonE&) = delete;
	static SingletonE _sInstance;
};

//类中静态的东西在外边初始化
SingletonE SingletonE::_sInstance;

//懒汉式(第一次使用实例对象时创建、复杂)
class SingletonL
{
public:
	static SingletonL* GetInstance()
	{
		
		if(_spInstance == nullptr)
		{
			_spInstance = new SingletonL;
		}
		return _spInstance;
	}
private:
	SingletonL(){}
	static SingletonL* _spInstance;
};
SingletonL* SingletonL::_spInstance = nullptr;

int main(int argc, char* argv[])
{
	cout << &SingletonE::GetSingletonE() << endl;
	cout << &SingletonE::GetSingletonE() << endl;

	cout << SingletonL::GetInstance() << endl;
	cout << SingletonL::GetInstance() << endl;
	return 0;
}
