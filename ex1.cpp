#include<iostream>
#include<vector>
using namespace std;

int MaxSum(vector<int> &a,int N)
{
	int thissum, maxsum;
	int i;
	thissum = maxsum = 0;
	for (i = 1; i < N; i++)
	{
		thissum += a[i];
		if (thissum>maxsum)
		{
			maxsum = thissum;
		}
		else if(thissum<0)
		{
			thissum = 0;
		}
	}
	return maxsum;
}
int main()
{
	vector<int> number;
	int i;
	while (cin>>i)
	{
		number.push_back(i);
	}
	cout << MaxSum(number,number.size()) << endl;
	return 0;

}