#include<iostream>
using namespace std;
typedef struct Polynode *poly;   
struct Polynode       //节点
{ 
	int first;
	int data;
	int next;
	poly link;
};
void createpoly(int f, int d,int n, poly *prear)   //生成每个节点
{
	poly p;
	p = new Polynode;
	p->first = f;
	p->data = d;
	p->next = n;
	p->link = NULL;
	(*prear)->link = p;
	*prear = p;
}
poly readpoly(int N)  //读入并生成链表
{
	poly P, rear, t;//rear指向链表的实时位置
	P = new Polynode;;
	P->link = NULL;
	rear = P;
	int f, d, n;
	while (N--)
	{
		cin >> f >> d>>n;
		createpoly(f,d,n,&rear);
	}
	t = P; P = P->link; delete t;
	return P;
}
poly sort(poly pr,int first,int N)
{
	poly p,t,t1,t2,rear;
	p = new Polynode;
	p->link = NULL;
	rear = p;
	t1 = pr;
	while (t1)
	{
		if (t1->first == first)
		{
			p->first = t1->first;
			p->data = t1->data;
			p->next = t1->next;
			break;
		}
		else
		{
			t1 = t1->link;
		}
	} 
	while (N--)
	{  
		t2 = pr;
		while (t2)
		{
			if (t2->first == rear->next)
			{
				createpoly(t2->first, t2->data, t2->next, &rear);
				break;
			}
			else {
				t2= t2->link;
			}
		}
	}
	return p;
}
void print(poly p)
{
	int flag = 0;
	if (!p)
	{
		cout << "error" << endl;
		return;
	}
	while (p)
	{
		if (p->next != -1)
		{
			cout.fill('0');//设置填充量
			cout.width(5);//设置域宽
			cout << p->first << " ";
			cout << p->data << " ";
			cout.fill('0');//设置填充量
			cout.width(5);//设置域宽
			cout << p->next << endl;
		}
		else
		{
			cout.fill('0');//设置填充量
			cout.width(5);//设置域宽
			cout << p->first << " ";
			cout << p->data << " "<< p->next << endl;
		}
		p = p->link;
	}
}
poly listReverse(poly head, int k)
{
	int count = 1;
	poly p;
	p = new Polynode;
	p->link = head;
	poly ne = p->link;
	poly old = ne->link;
	poly tmp = NULL;
	while (count < k) 
	{
			tmp = old->link;
			old->link = ne;
			old->next = ne->next;
			ne = old;
			old = tmp;
			count++;
		}
		p->link->link = old;
		if (old != NULL) {

			p->link->next = old->first;
		}
		else {

			p->link->next = -1;
		}
		return p;

}
int main()
{
	poly p;
	int firstAddress, N, K;
	cin >> firstAddress >> N >> K;
	p=readpoly(N);
	p = sort(p, firstAddress,N);

	p = listReverse(p, K);
	print(p);
	return 0;
}

