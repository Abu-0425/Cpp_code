#include <iostream>
using namespace std;

//缺省的默认参数最好在函数声明时给出
void TestFunc(int a = 10, int b = 20, int c = 30);


//命名空间
namespace N {
	int a = 10;
	int b = 20;
	int add(int x, int y)
	{
		return x + y;
	}
}

//int a = 20;

//using  namespace N;
//using N::a;

//缺省参数、默认参数
void TestFunc(int a, int b, int c)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//函数重载
//在相同作用域中，函数名必须相同，但函数列表必须不同
//参数列表不同的体现：
//1.参数个数不同 2.参数类型不同 3.参数次序不同
//注意：如果仅仅是函数返回值类型不同，则不能构成函数重载

double Add(double a, double b)
{
	return a + b;
}

int Add(int a, int b)
{
	return a + b;
}

long Add(long a, long b)
{
	return a + b;
}


int main()
{
	int ret1 = Add(10, 20);
	cout << "int : a + b = " << ret1 << endl;
	double ret2 = Add(1.2, 2.4);
	cout << "double : a + b = " << ret2 << endl;
	int ret3 = Add(10L, 20L);
	cout << "long : a + b = " << ret3 << endl;
	printf("'1' + '2' = %d\n",Add('1', '2'));//char和int存在隐式类型转换,所以会调用int Add
	
	//TestFunc();
	//TestFunc(1);
	//TestFunc(1, 2);
	//TestFunc(1, 2, 3);
	//int a = 30;
	//cout << a << endl;
	//cout << ::a << endl;
	//cout << N::a << endl;

	system("pause");
	return 0;
}