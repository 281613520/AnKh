/*do it by AnKh 2016.5.21*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int xx[30];//����
int zx[30];//����
int hx[30];//����
int n;//����Ľڵ�����
void input()
{
	stack<int> tmp;
	int N;
	int i = 0, j = 0;//i������������j����������
	string request;
	int key;
	cin >> N;
	n = N;
	int a;//N��2��
	a = 2 * N;
	if (a)
	{
		for (int k = 0; k < a; k++)
		{  
			cin >> request ;
			if (request=="Push")
			{   
				cin >> key;
				tmp.push(key);
				xx[i] = key;
				i++;
			}
			else if (request == "Pop") {
				zx[j] = tmp.top();
				tmp.pop();
				j++;
			}
		}
	}
	else {
		cout << "no tree" << endl;
	}


}

int hxtraversal(int xxL,int zxL,int hxL,int N)//xxL���������zxL���������hxL���������Nÿ�δ��������ĳ���
{   
	if (N == 0)
	{
		return -1;
	}
	if (N == 1) {
		hx[hxL] = xx[xxL];
		return -1;
	}
	int root = xx[xxL];
	hx[hxL+N-1] = root;
	for (int j=0; j < n; j++)
	{
		if (root == zx[j])
		{
			root = j;
			break;
		}
	}
	int L = root;//��߳���
	int R = N - L - 1;//�ұ߳���
	hxtraversal(xxL+1,zxL,hxL,L);
	hxtraversal(xxL+L+1,zxL+L+1,hxL+L,R);
}
int main()
{
	input();
	/*for (int i = 0; i<n; i++)
	{
		cout << xx[i] << " ";
	}
	cout << endl;
	for (int i = 0; i<n; i++)
	{
		cout << zx[i] << " ";
	}*/
	//��������
	hxtraversal(0,0,0,n);//�������
	for (int a=0; a < n; a++)
	{
		if (a != n - 1)
		{
			cout << hx[a] << " ";
		}
		else if (a == n - 1)
		{
			cout << hx[a];
		}
	}
	return 0;

}