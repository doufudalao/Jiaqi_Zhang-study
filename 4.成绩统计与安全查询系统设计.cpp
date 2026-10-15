#include<iostream>
#include<string>
using namespace std;
#define Max 100





////成绩单结构体
//class ScoreSheet
//{
//	
//	int score[Max];//成绩数组;
//	int n;//成绩数量;
//	
//};

//初始化成绩数组
void initScore(int* score, int n)
{
	for (int i = 0;i < n;i++)
	{
		score[i] = 0;
	};
}


//录入成绩
void inputScore(int* score, int n)
{
	if (n == Max)
	{
		cout << "成绩单超载，无法录入成绩！" << endl;
	}
	else
	{
		cout << "请输入成绩1-100之间的成绩：" << endl;
		for (int i = 0;i < n;i++)
		{
			cin >> score[i];
			if (score[i] < 0 || score[i] > 100)
			{
				cout << "成绩输入错误，请重新输入！" << endl;
				i--;
			}
		}
	}
}

//计算平均成绩
double claculateAverage(int* score, int n)//为什么要传入地址？因为数组名就是数组的首地址
{
	//计算成绩总和
	double sum = 0;
	for (int i = 0;i < n;i++)
	{
		sum += score[i];
	}
	//计算平均成绩
	return sum / n;

}

//安全查询
int safeGet(const int* score, int n, int index)
{
	if (index < 0 || index >= n)
	{
		cout << "下标越界！" << endl;
		return -1;
	}

	//返回成绩
	return score[index];
}

//统计分数段
void countGrade(const int* score, int n,int* count)
{
	//int count[5] = { };
	for (int i = 0;i < n;i++)
	{
		if (score[i] >= 90)
		{
			count[0]++;

		}
		else if (score[i] >= 80)
		{
			count[1]++;

		}
		else if (score[i] >= 70)
		{
			count[2]++;

		}
		else if (score[i] >= 60)
		{
			count[3]++;
			 
		}
		else
		{
			count[4]++;

		}

	}
	cout << "90分以上的人数为：" << count[0] << endl;
	cout << "80-89分的人数为：" << count[1] << endl;
	cout << "70-79分的人数为：" << count[2] << endl;
	cout << "60-69分的人数为：" << count[3] << endl;
	cout << "60分以下的人数为：" << count[4] << endl;
	
}

//读取最高分和最低分
void findMinMax(const int* score, int n, int* min, int* max)
{
	//初始化最高分和最低分
	*min = score[0];
	*max = score[0];

	for (int i = 0;i < n;i++)
	{
		if (*min > score[i])
		{
			*min = score[i];

		}
		if (*max < score[i])	
		{
			*max = score[i];

		}

	}

	cout << "最高分为：" << *max << endl;
	cout << "最低分为：" << *min << endl;
}
//打印所有结果
void printResult(const int* score, int n, double avg, int* count, int max, int min)
{

	cout << "成绩单如下：" << endl;
	for (int i = 0;i < n;i++)
	{
		cout << i << "号成绩为：" << score[i] << endl;
	}
	cout << "平均成绩为：" << avg << endl;
	cout << "最高分为：" << max << endl;
	cout << "最低分为：" << min << endl;
	cout << "90分以上的人数为：" << count[0] << endl;
	cout << "80-89分的人数为：" << count[1] << endl;
	cout << "70-79分的人数为：" << count[2] << endl;
	cout << "60-69分的人数为：" << count[3] << endl;
	cout << "60分以下的人数为：" << count[4] << endl;
}
	



int main()
{
	int score[Max];//成绩数组;


	
	int n;//成绩数量;
	int count[5] = { 0 };//分数段统计数组;
	int max, min;//最高分和最低分;
	double avg;//平均成绩;
	int testIndex;//测试下标;


	//初始化数组
	initScore(score, Max);

	//读取学生人数
	cout<<"请输入学生人数（不超过100人）：" << endl;
	cin >> n;

	//调用各函数
	inputScore(score, n);

	avg = claculateAverage(score, n);

	findMinMax(score, n, &min, &max);

	countGrade(score, n, count);

	//安全查询

    cout<< "请输入要查询的成绩下标：" << endl;

	//用循环保证输入合法
	do
	{
		cin >> testIndex;
		int queried = safeGet(score, n, testIndex);
		if (queried == -1)
		{
			cout << "查询失败！请重新输入！" << endl;
		}
		else
		{
			cout << testIndex << "号成绩为：" << queried << endl;
			system("pause");


		}
	} while (testIndex < 0 || testIndex >= n);
	
	//打印所有结果
	printResult(score, n, avg, count, max, min);

	return 0;


}