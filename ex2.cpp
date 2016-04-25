#include<iostream>
#include<vector>
using namespace std;

void MaxSum(vector<int> &a, int N)
{
	int thissum, maxsum;
	int i;
	int first, last;
	int tmpf, tmpl;
	thissum = maxsum = 0;
	tmpf = 1;
	for (i = 1; i < N; i++)
	{
		if (thissum >= 0)
		{
			thissum += a[i];
			tmpl = i;
		}
		else
		{   
			thissum = 0;
			thissum += a[i];
			tmpf = i;
			tmpl = i;
		}
		if (thissum > maxsum || thissum == 0)
		{
			maxsum = thissum;
			first = tmpf;
			last = tmpl;
		}
	}
	cout << maxsum << " " << a[first] << " " << a[last] << endl;
}
int main()
{
	vector<int> number;
	int i;
	while (cin >> i)
	{
		number.push_back(i);
	}
	MaxSum(number, number.size());
	return 0;

}