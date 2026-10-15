#include<iostream>
#include<string>
using namespace std;


//计算爬到第n级台阶有多少种方法
long long climbStairsIter(int n)
{

	long long a = 1;
	long long b = 1;
	long long c;

	//迭代计算 将第n级台阶的走法数表示为前两级台阶走法数之和
	//从第二阶开始 所以i=2,一直加到第n阶 所以i <= n
	for(int i=2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

//递归计算爬到第n级台阶有多少种方法
//climbStairsRec(n) = climbStairsRec(n-1) + climbStairsRec(n-2)
long long climbStairsRec(int n)
{

	if (n == 0 || n == 1)
	{
		return 1;

	}
	else
		return climbStairsRec(n - 1) + climbStairsRec(n - 2);
}


int main()
{
	int n;
	cout << "请输入有几级阶梯" << endl;
	cin >> n;
	cout << "使用迭代方法计算爬到第" << n << "级阶梯有" << climbStairsIter(n) << "种方法" << endl;
	cout << "使用递归方法计算爬到第" << n << "级阶梯有" << climbStairsRec(n) << "种方法" << endl;
	
	return 0;
	system("pause");
}