#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int t;
int month[12];
int charge[4];
int minCharge;

void dfs(int mon, int sum)
{
	if (mon > 11)
	{
		if (minCharge > sum)minCharge = sum;
		return;
	}
	dfs(mon + 1, sum + month[mon] * charge[0]);
	dfs(mon + 1, sum + charge[1]);
	dfs(mon + 3, sum + charge[2]);
}
int main()
{
	scanf("%d", &t);
	for (int u = 1; u <= t; u++)
	{
		for (int i = 0; i < 4; i++)
		{
			int ch;
			scanf("%d", &ch);
			charge[i] = ch;
		}
		for (int i = 0; i < 12; i++)
		{
			int num;
			scanf("%d", &num);
			month[i] = num;
		}
		minCharge = 100000000;
		dfs(0, 0);
		printf("#%d %d\n", u, minCharge < charge[3] ? minCharge : charge[3]);

	}
	return 0;
}
