//#include <iostream>
//
//using namespace std;
//
//template <class T1, class T2>
//T1 fun(T1 t1, T2 t2)
//{
//	return t1 + t2;
//}
//
//int main(void)
//{
//	cout << fun(2, 5.0) << endl;
//	return 0;
//}
#if 0
template<class T>
T Func(const T& x1, const T& x2)
{
	return x1 - x2;
}
int main()
{
	Func(10, 20);
	Func(10.0, 20.0);
	//Sub(a1, d1);这样不行，两个类型编译器不知道要用那个类型生成新的代码
	//解决方法:1.将d1强制类型转换为int或者把a1强制类型转换为double
	Func(10, (int)20.0);
	//2.采用显示实例化
	Func<int>(10, 20.0);
	return 0;
}

#endif