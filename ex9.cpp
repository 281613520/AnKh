#include <iostream>
using namespace std;
typedef TreeNode* node;
struct  TreeNode 
{
	int Data;
	node Left;
	node Right;
};//���ڵ�
node readtree(int n,int l)//����ڵ�����
{
	node p;
	int data[10];
	int i;//ѭ��
	p = new TreeNode;
	p->Right = NULL;
	p->Left = NULL;
	cin >> data[0];
	p->Data = data[0];
	for (i = 1; i<l;i++)
	{
		cin >> data[i];
		insert(p, data[i]);
	}
	return p;
}
void insert(node p,int data)
{
	node p1;
	p1 = new TreeNode;
	p1->Right = NULL;
	p1->Left = NULL;
	p1->Data = data;
	if (p1->Data < data)
	{
		(*prear)->Left = p;
	}
	else {
		(*prear)->Right = p;
	}
	
}
bool comparetree(node p1,node p2)//�Ƚ���
{
	return true;
}
int main()
{
	int N;
	cin >> N;
	while (N) 
	{
		int L, l;
		cin >> L;
		l = L + 1;
		node p[100];
		//	����
		for (int i = 0; i < l; i++)
		{
			p[i] = readtree(N,l);
		}
		//  �Ƚ�
		for (int j = 1; j < l; j++)
		{
			if (comparetree(p[0],p[j]))
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		break;
	}
	return 0;
}