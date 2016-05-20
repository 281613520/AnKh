#include<iostream>
#include<stack>
using namespace std;
int xx[30];//先序
int zx[30];//中序
int hx[30];//后序

void input()
{   
	stack<int> tmp;
	int N;
	int i=0, j=0;//i用来计数先序，j来计数后序
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
	//建树？
	//后序遍历并输出
	return 0;

}