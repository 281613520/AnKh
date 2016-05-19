#include<iostream>
#define Null -1;
using namespace std;
struct Tree {
	int left;
	int right;
	char word;
}t1[10], t2[10];
int createtree(Tree t[])
{
	int Root;
	int N;
	char cl, cr;
	cin >> N;
	int check[10] = {0};

	if (N) {
		for (int i = 0; i < N; i++) {
			cin >> t[i].word >> cl >> cr;
			if (cl != '-') {
				t[i].left = cl - '0';
				check[t[i].left] = 1;
			}
			else t[i].left = Null;
			if (cr != '-') {
				t[i].right = cr - '0';
				check[t[i].right] = 1;
			}
			else t[i].right = Null;
		}
		for (int i = 0; i < N; i++)
		{
			if (!check[i]) {
				Root = i;
				break;
			}
		}
	}
	else
	{
		Root = -1;
	}

	return Root;

}
bool compare(int r1, int r2)
{
	if (r1 == -1 && r2 == -1)
		return 1;
	if ((r1 != -1 && r2 == -1) || (r1 == -1 && r2 != -1))
		return 0;
	if (t1[r1].word != t2[r2].word)// ���ڵ�ֵvalue�����
		return false;
	if ((t1[r1].left == -1)&&(t2[r2].left == -1))// �����������Կ� ת���ж�������
		return compare(t1[r1].right, t2[r2].right);

	if ((t1[r1].left != -1) && (t2[r2].left != -1) &&
		((t1[t1[r1].left].word) == (t2[t2[r2].left].word)))// �����������Բ��� ������������ֵ���
	{
		return (compare(t1[r1].left, t2[r2].left) &&
			compare(t1[r1].right, t2[r2].right));// ת����·�ݹ��ж����ߵ�����
	}
	else {
		return (compare(t1[r1].left, t2[r2].right) &&
			compare(t1[r1].right, t2[r2].left));// ������������һ���� �� �Բ��յ�ֵ����� �򽻻������������ж�
	}

}

int main()
{
	int r1 = createtree(t1);//jianshu
	int r2 = createtree(t2);
	if (compare(r1, r2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
