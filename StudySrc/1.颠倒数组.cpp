#include<iostream>
using namespace std;
#include<string>

//倒序函数(使用指针编写）
void reverseArray(int* arr, int n) 
{
	for (int i = 0;i<n/2;i++)
	{
		
		int temp = *(arr+i);
        *(arr + i) = *(arr + n- 1-i);
		*(arr + n - 1 - i) = temp;
		
    }

}
//reverseArray
//测试函数 打印数组
void test (int* arr,int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << *arr << "  ";
		arr++;
	}
	cout << endl;
}


int main()
{
	//输入数组的长度n和数组元素

	//使用do...while可以先执行 后输入
	int n;
	do
	{
		cout << "请输入数组长度" << endl;
		cin >> n;


		if (n < 1 || n>100)
		{
			cout << "数组必须在1到100之间！" << endl;

		}
	} while (n < 1 || n>100);
	
	
	//动态分配数组 如果在for中新建数组 会在for结束后消失
	int* arr = new int[n];

	for (int i = 0;i < n;i++)
	{
		cout<<"请输入第" << i + 1 << "个元素" << endl;
		cin >> arr[i];
	}
	

	cout << "Before reverse: " << endl;
	test(arr, n);

	//调用函数reverseArray()来反转数组
	reverseArray(arr, n);
	cout << "After reverse: " << endl;
	test(arr, n);



	
}