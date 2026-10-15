#include<iostream>
#include<string>
using namespace std;
#define Max 100


//菜单界面
void showMenu()
{
	cout << "****************************" << endl;
	cout << "****************************" << endl;
	cout << "*****                  *****" << endl;
	cout << "*****  1.录入成绩      *****" << endl;
	cout << "*****  2.计算平均成绩  *****" << endl;
	cout << "*****  3.查询成绩      *****" << endl;
	cout << "*****  4.统计分数段    *****" << endl;
	cout << "*****  5.读取最高/低分 *****" << endl;
	cout << "*****  6.打印所有结果  *****" << endl;
	cout << "*****  0.退出系统      *****" << endl;
	cout << "*****                  *****" << endl;
	cout << "****************************" << endl;
	cout << "****************************" << endl;

}

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
	

	//录入前初始化成绩数组
	initScore(score, n);


	
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

	system("pause");
	system("cls");
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
	double avg = sum / n;
	cout << "平均成绩为：" << avg << endl;
	system("pause");
	system("cls");
	return avg;
}


//安全查询1
int safeGet(const int* score, int n, int index)
{
	if (index < 0 || index >= n)
	{
		cout << "下标越界！" << endl;
		return -1;
	}

	//返回成绩
	return score[index];
};

//安全查询2


void safeGet2(const int* score, int n)
{
	int index;

	cout << "请输入要查询的成绩下标：" << endl;

	//用循环保证输入合法
	do
	{
		cin >> index;
		int queried = safeGet(score, n, index);
		if (queried == -1)
		{
			cout << "查询失败！请重新输入！" << endl;
		}
		else
		{
			cout << index << "号成绩为：" << queried << endl;
			


		}
	} while (index < 0 || index >= n);

	system("pause");
	system("cls");
}


   //统计分数段
	void countGrade(const int* score, int n, int* count)
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

		system("pause");
		system("cls");
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

		system("pause");
		system("cls");
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

		system("pause");
		system("cls");
	}

	int main()
	{
		int score[Max];//成绩数组;
        int n;//成绩数量;
		int count[5] = { 0 };//分数段统计数组;
		int max, min;//最高分和最低分;
		double avg=0.0;//平均成绩;
		int testIndex;//测试下标;

		cout << "请输入学生人数（不超过100人）：" << endl;
		cin >> n;

		int slecet = 0;
		while (1)
		{
			

			//菜单调用
			showMenu();
			cout << "请输入需要调用的功能" << endl;
			cin >> slecet;


			switch (slecet)
			{
			case 1://录入成绩
				inputScore(score, n);
				break;
			case 2://计算平均成绩
				//avg = claculateAverage(score, n);
				claculateAverage(score, n);
				break;
			case 3://安全查询
				safeGet2(score, n);
				break;
			case 4://统计分数段
				countGrade(score, n, count);
				break;
			case 5://读取最高分和最低分
				findMinMax(score, n, &min, &max);
				break;
			case 6://打印所有结果，这个功能不全。
				//因为打印所有结果需要调用前面所有的函数
				//我希望这段代码更简洁美观，更好的选择是在弄一个结构体储存所有的数据，
				// 但因为我交作业的时间太晚，所以我没有来得及完善 ，请大佬们见谅
				printResult(score, n, avg, count, max, min);
				break;
			case 0://0.退出系统
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
				break;//此处break不是必须 但是编码美观与习惯需要加break
			default:
				break;


			}

		}
		system("pause");
		return 0;
	}
