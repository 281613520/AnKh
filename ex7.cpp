#include<iostream>
#include<queue>
using namespace std;
#define MAX 10;

struct tree
{ 
	int left;
	int right;
}T[10];

int build(tree t[])
{
	int N,root;
	int check[10];
	char tr, tl;
	cin >> N;
	if (N)
	{
		for (int i = 0; i < N; i++) check[i] = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> tl >> tr;
			if (tl != '-')
			{
				t[i].left = tl - '0';
				check[t[i].left] = 1;
			}
			else
			{
				t[i].left = -1;
			}
			if (tr != '-')
			{
				t[i].right = tr - '0';
				check[t[i].right] = 1;
			}
			else
			{
				t[i].right = -1;
			}
			
		}
		for (int i = 0; i < N; i++)
		{
			if (!check[i])break;
			root = i;
		}
	}
	return root;
}

int PrintTree(int root)
{
	/*if (root == -1)
		return 0;
	else
		cout << root << " ";
	if (T[root].left != -1 && T[root].right != -1)
	{
		PrintTree(T[root].left);
		PrintTree(T[root].right);
	}
	if (T[root].left != -1 && T[root].right == -1) {
		PrintTree(T[root].left);
	}
	if (T[root].left == -1 && T[root].right != -1) {
		PrintTree(T[root].right);
	}
	if (T[root].left == -1 && T[root].right == -1) {
		return 0;
	}*/
	////将树压入队列，再依次弹出
	//queue<int> Q;
	//Q.push(root);


}
int main()
{
	int r = build(T);//jianshu
	PrintTree(r);//bianli daying
	return 0;
}