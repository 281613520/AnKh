#include<iostream>
 
using namespace std;

typedef struct Polynode* polynomial;
struct Polynode
{
	int c;
	int ex;
	polynomial link;
};

void createpoly(int c, int e, polynomial *prear)
{
	polynomial p;
	p = new Polynode;
	p->c = c;
	p->ex = e;
	p->link = NULL;
	(*prear)->link = p;
	*prear = p;
}

polynomial readpoly()
{
	polynomial P, rear,t;//rear指向链表的实时位置
	P = new Polynode;;
	P->link = NULL;
	rear = P;
	int c,ex,N;
	cin >> N;//非零项个数
	while (N--)
	{
		cin >> c >> ex;
		createpoly(c, ex, &rear);
	}
	t = P; P = P->link;delete t;
	return P;
}
polynomial addpoly(polynomial p1,polynomial p2)
{  
	polynomial t1, t2, p,rear,t;
	int sum;
	p = new Polynode;;//申请新空间
	p->link = NULL;
	rear = p;
	t1 = p1, t2 = p2;
	while (t1&&t2)
	{
		if (t1->ex == t2->ex)
		{
			sum = t1->c + t2->c;
			if (sum)
			{
				createpoly(t1->c + t2->c, t1->ex, &rear);
			}
			t1 = t1->link;
			t2 = t2->link;
		}
		else if(t1->ex > t2->ex)
		{
			createpoly(t1->c, t1->ex, &rear);
			t1 = t1->link;
		}
		else
		{
			createpoly(t2->c, t2->ex, &rear);
			t2 = t2->link;
		}
	}
	while(t1)
	{
		createpoly(t1->c, t1->ex, &rear);
		t1 = t1->link;
	}
	while (t2) 
	{
		createpoly(t2->c, t2->ex, &rear);
		t2 = t2->link;
	}
	t = p;
	p = p->link;
	delete t;
	return p;
}
polynomial multipoly(polynomial p1, polynomial p2)
{
	polynomial p, rear, t1, t2, t;
	int c, e;
	if (!p1||!p2)
	{
		return NULL;
	}
	t1 = p1, t2 = p2;
	p = new Polynode;;
	rear = p;
	while (t2)
	{
		createpoly(t1->c*t2->c ,t1->ex+t2->ex,&rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1)
	{
		t2 = p2; rear = p;
		while (t2)
		{
			e = t1->ex + t2->ex;
			c = t1->c*t2->c;
			while (rear->link&&rear->link->ex > e)
			{
				rear = rear->link;
			}
			if (rear->link&&rear->link->ex == e)
			{
				if (rear->link->c + c)
				{
					rear->link->c += c;
				}
				else
				{
					t = rear->link;
					rear->link = t->link;
					delete t;
				}
			}
			else
			{
				t = new Polynode;
				t->c = c; t->ex = e;
				t->link = rear->link;
				rear->link = t;
				rear = rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = p; p = p->link; delete t2;
	return p;
}
void printpoly(polynomial p)
{
	int flag = 0;
	if (!p)
	{
		cout << "0 0" << endl;
		return;
	}
	while (p)
	{
		if (!flag)
			flag = 1;
		else
			cout << " ";
		cout << p->c <<" "<< p->ex ;
		p = p->link;
	} 
	cout << endl;
}
int main()
{
	polynomial p1, p2,pa,pm;
	p1=readpoly();//输入第一个多项式
	p2 = readpoly();//输入第二个多项式
	pm = multipoly(p1, p2);
	printpoly(pm);
	pa = addpoly(p1, p2);
	printpoly(pa);
	return 0;
}
