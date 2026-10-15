#include<iostream>
using namespace std;
//前序遍历 左 根 右
void preOrderTraversal(const int* tree, int n, int i)
{
	//对于i超过n或空树的情况，直接返回
	if (i >= n || tree[i] < -1)
	{
		return;
	}

	cout << tree[i] << "  ";
	//递归就是先把函数一直调用自己 写明确终止条件
	//递归左子树
	preOrderTraversal(tree, n, 2 * i + 1);
	//递归右子树
	preOrderTraversal(tree, n, 2 * i + 2);

}

//中序遍历 根 左 右
void inOrderTraversal(const int* tree, int n, int i)
{
	if (i >= n || tree[i] < -1)
	{
		return;

	}
	inOrderTraversal(tree, n, 2 * i + 1);
	cout << tree[i] << "  ";
	inOrderTraversal(tree, n, 2 * i + 2);
}

void postTraversal(const int* tree, int n, int i)
{
	if (i >= n || tree[i] < -1)
	{
		return;
	}
	postTraversal(tree, n, 2 * i + 1);
	postTraversal(tree, n, 2 * i + 2);
	cout << tree[i] << "  ";
}


void testTree()
{
	int n;
	cout<<"请输入二叉树的节点个数：";
	cin >> n;

	//动态分配内存
	//创建一个大小为n的数组来存储二叉树的节点值，前面必须创建n
	int* tree = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout<< "请输入第" << i + 1 << "个节点的值：";
		cin >> tree[i];
	}

	cout << "前序遍历结果为：";
	preOrderTraversal(tree, n, 0);
	cout << endl;

	cout << "中序遍历结果为：";
	inOrderTraversal(tree, n, 0);
	cout << endl;

	cout << "后序遍历结果为：";
	postTraversal(tree, n, 0);
	cout << endl;

	//释放动态分配的内存
	delete[] tree;
}


int main()
{
	testTree();
	return 0;
}