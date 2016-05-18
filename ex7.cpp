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
	
	char tr, tl;
	cin >> N;
	int check[10];//ур╦Ы╫з╣Ц
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
			if (check[i]==0)break;
			root = i+1;
		}
	}
	return root;
}

void PrintTree(int root)
{
	queue<int> Q;
	int node;
	if (!root)
	{
		cout << "empty" << endl;;
	}
	Q.push(root);
	while (!Q.empty())
	{
		node = Q.front();
		Q.pop();
		cout << node << " ";
		if (T[node].left!=-1)
			Q.push(T[node].left);
		if(T[node].right!=-1)
			Q.push(T[node].right);
	}
}
int main()
{
	int r = build(T);//jianshu
	PrintTree(r);//bianli daying
	system("pause");
	return 0;
}