#include<iostream>
#include<stack>
using namespace std;
int xx[30];//����
int zx[30];//����
int hx[30];//����

void input()
{   
	stack<int> tmp;
	int N;
	int i=0, j=0;//i������������j����������
	char request;
	int key;
	cin >> N;
	if (N)
	{ 
		for (int k = 0; k < N;k++)
		if (cin >> request >> key)
		{
			tmp.push(key);
			xx[i] = key;
			i++;
		}
		else {
			zx[j] = tmp.top();
			tmp.pop();
			j++;
		}
		



	}
	else {
		cout << "no tree" << endl;
	}


}

int main()
{
	//������
	//������������
	return 0;

}